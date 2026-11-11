#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int ans_num[M];
int n,m;
int a[N];
int paiYiChu[M];
int paiout[N];
int out[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		//cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int outl=INT_MAX,outr=INT_MIN;
		memset(paiYiChu,0,sizeof paiYiChu);
		memset(out,0,sizeof out);
		paiout[1]=1,paiout[i]--;
		for(int j=i;j<=n;j++){
			if(paiYiChu[a[j]]!=0 && out[paiYiChu[a[j]]]==0){
				for(int k=paiYiChu[a[j]];k<=j-1;k++){
					out[k]=1;
				}
			}
			paiYiChu[a[j]]=j;
		}
		for(int j=i;j<=n;j++){
			if(out[j]==0)ans_num[a[j]]++;
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<ans_num[i]<<' ';
	}
	
	return 0;
}/*
10 3
3 1 2 1 3 2 3 1 2 1*/
