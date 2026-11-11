#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010],mx,s; 
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=1;j<=n-i;j++){
				if(a[i]&a[i+j]>mx) mx=a[i]&a[i+i];
			}
		}
		cout<<mx;
	}
	if(m==3){
		for(int i=1;i<n-1;i++){
			for(int j=1;j<n-i;j++){
				for(int k=1;k<=n-i-j;k++){
					s=a[i]&a[i+j];
					s=s&a[i+j+k];
					if(s>mx){
						mx=s;
					}
				}
			}
		}
		cout<<mx;
	}
	if(m>3){
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=m;i++){
			s=s&a[i];
		}
		if(s>mx) mx=s;
		cout<<mx;
	}
	return 0;
}
