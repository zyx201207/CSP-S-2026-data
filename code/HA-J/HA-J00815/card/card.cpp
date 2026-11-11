#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],ton[M],ans[M],t[N];
bool f;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen("D:\\down\\card\\card4.in","r",stdin);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	//freopen("D:\\down\\card\\card.txt","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])f=1;
		ton[a[i]]=i;
	}
	if(f){
		for(int i=1;i<=n;i++){
			int idx=0;
			memset(ton,0,sizeof(ton));
			for(int j=i;j<=n;j++){
				if(ton[a[j]]){
					for(int k=ton[a[j]]+1;k<=idx;k++)ton[t[k]]=0,t[k]=0;
					idx=ton[a[j]];
				}
				else t[++idx]=a[j],ton[a[j]]=idx;
			}
			for(int j=1;j<=idx;j++){
				ans[t[j]]++;
			}
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	}
	else{
		for(int i=1;i<=m;i++)cout<<ton[i]<<' ';
	}
	
	return 0;
}

