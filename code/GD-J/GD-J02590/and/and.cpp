#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;int mx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			mx=(max(mx,a[i]));
		}
		cout<<mx;
		return 0;
	}
	if(m==(n-1)){
		for(int i=1;i<=n;i++){
			int sum=a[1];
			for(int j=2;j<=n;j++){
				sum=sum|a[j];
			}
			mx=max(mx,sum);
		}
		cout<<mx;
		return 0;
	}
	if(m==n){
		mx=a[1];
		for(int i=1;i<=n;i++){
			mx=mx|a[i];
		}
		cout<<mx;
		return 0;
	} 
	sort(a+1,a+n+1);int num=a[1];
	for(int i=1;i<=m;i++){
		num=num|a[i];
	}
	cout<<num;
	return 0;
}

