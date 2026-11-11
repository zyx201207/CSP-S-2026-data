#include<bits/stdc++.h>
using namespace std;
int num[1000005],ans[1000005],dp[1000005],a[1000005],t[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		cin>>num[i];
		ans[num[i]]=i;
	}
	for(int sss=0;sss<n;sss++)
	{int k=sss;
	for(int i=1;i<=m;i++)t[i]=0;
	while(k<n){
		if(k==ans[num[k]])t[num[k]]=1,k++;
		else k=ans[num[k]],t[num[k]]=1;
		
	}
	for(int i=1;i<=m;i++)a[i]+=t[i];}
	for(int i=1;i<=m;i++)cout<<a[i]<<" ";
	return 0;
	
}
