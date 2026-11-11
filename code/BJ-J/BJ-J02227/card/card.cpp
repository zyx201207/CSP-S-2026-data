#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

int k[500005];
int cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>k[i];
	cnt[k[n-1]]=n;
	int t=k[n-1];
	for(int i=0;i<n;i++){
		if(k[i]!=t){
			cnt[k[i]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
		
	return 0;
}
