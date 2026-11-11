#include<bits/stdc++.h>
using namespace std;
int n,m,a[200003];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(m==n){
		for(int i=2;i<=n;i++)
			a[1]=a[1]&a[i];
		cout<<a[1];
	}
	if(m==1){
		int mx=0;
		for(int i=1;i<=n;i++)
		mx=max(mx,a[i]);
		cout<<mx;
	}
	if(m==2){
		int mx=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			mx=max(mx,a[i]&a[j]);
		cout<<mx;
	}
	return 0;
}
