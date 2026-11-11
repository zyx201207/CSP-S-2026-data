#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,m;
	cin>>c>>m;
	for(int i=1;i<=m;i++){
		ll a[100009]={0};
		ll q,w;
		ll zong=0;
		cin>>q>>w;
		int ji=0;
		bool b[100009]={0};
		for(int j=1;j<=q;j++){
			cin>>a[j];
			b[j]=b[j-1];
			if(a[j-1]+w<a[j]) b[j]=1;
			a[j+1]=9999999;
		}
		for(int j=1;j<q;j++){
			if(b[j+3]!=1&&j+2!=q&&b[j]==0&&a[j+1]-a[j]<w&&a[j+2]-a[j]<=w&&a[j+3]-a[j]>w){
				zong++;
			}
		}
		cout<<zong<<endl;
	}
	
	
	return 0;
} 
