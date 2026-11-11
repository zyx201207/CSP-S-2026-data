#include "bits/stdc++.h"
using namespace std;
int n,m;
int a[500001];
//#define int long long
int js(int a[],int ks,int n,int m){
	int tj[m+1][3];
	int sum=0;
	for(int i = ks;i <= n;i++){
		if(tj[a[i]][1]){
			for(int j = 1;j <= n;j++)if(tj[a[j]][2] > tj[a[i]][2])tj[a[j]][1]=tj[a[j]][2]=0,sum--;
		}
		sum=max(sum,0);
		tj[a[i]][1]++,sum++,tj[a[i]][2]=i;
	}
	return sum;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int sc[m+1]={0};
	for(int i = 1;i <= n;i++)cin>>a[i];
	for(int i = 1;i <= n;i++){
		int num=js(a,i,n,m);
		sc[num]++;
	}
	for(int i = 1;i <= m;i++)cout<<sc[i]<<' ';
}
