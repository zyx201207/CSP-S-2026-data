#include<bits/stdc++.h>
using namespace std;
int m,n,ma=-0x3f3f3f3f;
int a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//cout<<(3&12&1)<<endl;
	cin>>m>>n;
	int u;/*
	cin>>u;
	a[1]=u;
	for(int i=2;i<=m;i++){
		cin>>u;
		a[i]=a[i-1]&u;
	}
	for(int i=1;i<=m-n+1;i++){
		if(i!=1) ma=max(ma,a[i+n-1]&a[i-1]);
		else ma=max(ma,a[i+n-1]);
		cout<<ma<<endl;
	}
	cout<<ma;*//*
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m-n+1;i++){
		int op=a[i];
		for(int j=i+1;j<=i+n-1;j++){
			op=op&a[j];
		}
		ma=max(ma,op);
	}
	cout<<ma;*/
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+m);
	//for(int i=1;i<=m;i++) cout<<a[i];
	ma=a[m];
	for(int i=m-1;i>=m-n+1;i--){
		ma=ma&a[i];
	}
	//cout<<ma;
	int p=a[m-1];
	for(int i=m-2;i>=m-n;i--){
	   p=p&a[i];
	}
	cout<<max(ma,p);
	return 0;
}
