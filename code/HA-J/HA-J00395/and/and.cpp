#include<bits/stdc++.h>
using namespace std;
int a[200009];
int mx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<32){
		for(int i=1;i<=n-m+1;i++){
			int ai=a[i];
			for(int j=1;j<m;j++){
				ai=ai&a[i+j];
			}
			mx=max(mx,ai);
		}
		cout<<mx;
	}else{
		for(int i=1;i<=32-m+1;i++){
			int ai=a[i];
			for(int j=1;j<m;j++){
				ai=ai&a[i+j];
			}
			mx=max(mx,ai);
		}
		cout<<mx;
	}
	return 0;
}
