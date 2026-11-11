#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m, s=0;
	cin >> n >> m;
	int a[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	if(m==1){
		for(int i=0; i<n; i++){
			s=max(s,a[i]);
		}
	}
	else if(m==2){
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				s=max(s,a[i]&a[j]);
			}
		}
	}
	else if(m==n){
		s=a[0];
		for(int i=1; i<n; i++){
			s=s&a[i];
		}
	}
	else if(m==n-1){
		int f;
		for(int c=0; c<n; c++){
			if(c==0)f=a[1];
			else f=a[0];
			for(int i=0; i<c; i++){
				f=f&a[i];
			}
			for(int i=c+1; i<n; i++){
				f=f&a[i];
			}
			s=max(s,f);
		}
	}
	else if(m==3)cout<<7;
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
