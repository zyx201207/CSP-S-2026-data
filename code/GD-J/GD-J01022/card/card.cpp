#include<bits/stdc++.h>
using namespace std;

int n,m,ans,ad[1000005],zm[1000005],t[10000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ad[i];
	}
	for(int i=1;i<=n;i++){
		int l=1;
		int x=1;
		int pdw[1000005]={0,0};
		for(int j=i;j<=n;j++){
			zm[x]=ad[j];
			if(pdw[ad[j]]<=j&&pdw[ad[j]]>=l&&pdw[ad[j]]){
				l=x;
//				cout<<"ÒÆ¶¯"<<endl; 
			}else{
				pdw[ad[j]]=x;
			}
			x++;
//			for(int j=1;j<x;j++){
//				cout<<zm[j]<<' ';
//			}
//			cout<<endl;
		}
		for(int j=l;j<x;j++){
			t[zm[j]]++;
//			cout<<zm[j]<<' ';
		}
//		cout<<endl;
	}
	for(int j=1;j<=m;j++){
		cout<<t[j]<<' ';
	}
}
