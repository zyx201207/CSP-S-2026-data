#include <bits/stdc++.h>
using namespace std;
//9:55 响铃了
//10:15 响铃了  放弃了 
int a[50005],card[50005];
bool b[50005];
int n,k;
int ans[30005];
int in(int num){
	for(int i=0;i<n;i++)if(num==card[i])return i;
	else return -1;
}
int search(){
	for(int i=0;i<5000;i++)if(card[i]==0)return i; 
}

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int now=in(a[j]);
			if(now!=-1)for(int k=now;k<50000;k++)card[k]=0;
			card[search()]=a[j];
		}
		for(int j=0;j<search();j++){
			if(b[card[j]]==0){
				ans[card[j]]++;
				b[card[j]]=1;
			}	
		}
		memset(b,0,sizeof(b));
	}
	for(int i=1;i<=k;i++)cout<<ans[i]<<' ';
	return 0;
}
