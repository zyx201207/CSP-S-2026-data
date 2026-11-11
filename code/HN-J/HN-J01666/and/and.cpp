#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
//const int N1=1e9+5;
int n,m;
long long a[N];
//int mx=-0x3f3f3f3f;
//bool vis[N1][N];
bool cmp(int a,int b){
	return a>b;
}
int main(){ 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//f(m);
	/*
	int x[N];
	int p=0;
	for(int i=1;i<n;i++){
		//vis[a[i]][1]=1;
		if(x[1]<a[i]){
			x[1]=a[i];
			p=i;
		}
		//x[1]=max(x[1],a[i]);
		//mx=max(mx,vis[a[i]][j]);
		
	}
	cout<<x[1]<<endl;
	a[p]=0;
	for(int i=3;i<=m;i++){
		int q=0;
		for(int j=1;j<=n;j++){
			cout<<x[i-1]<<" "<<a[j]<<" "<<(x[i-1]&a[j])<<endl;
			if(x[i]<x[i-1]&a[j]){
				x[i]=x[i-1]&a[j];
				q=j;
			}
			
		}
		a[q]=0;
	}
	cout<<x[m];*/
	sort(a+1,a+1+n,cmp);
	int x=a[1];
	for(int i=2;i<=m;i++){
		//cout<<a[i]<<" ";
		x&=a[i];
	}
	cout<<x;
	return 0; 
}
