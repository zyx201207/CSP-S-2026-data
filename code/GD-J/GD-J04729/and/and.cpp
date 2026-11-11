#include <bits/stdc++.h> 
using namespace std;
int n,m,r=0;
int a[200000]; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if(m==1){
		for(int i=0;i<n;i++){
			int b = a[i];
			if(b>r){
				r=b;
			} 
		}
		cout << r;
	}
	else if(m==n){
		int r=a[0];
		for(int i=0;i<n;i++){
			r=r&a[i];
		} 
		cout << r;
	}
	else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=(i+1);j<n;j++){
				int b=a[i]&a[j];
				if(b>r){
					r=b;
				}
			}
		}
		cout << r;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
