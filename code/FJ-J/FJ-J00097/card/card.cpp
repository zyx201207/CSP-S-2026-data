#include<bits/stdc++.h>//bufen
using namespace std;
int n,m,ans[500005],a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int t[m+1]={0},q[n-i+2],k=0;
		for(int j=i;j<=n;j++){
			if(t[a[j]]<=k&&q[t[a[j]]]==a[j]) k=t[a[j]];
			else{
				k++;
				q[k]=a[j];
				t[a[j]]=k;
			}
		}
		for(int j=1;j<=k;j++)ans[q[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' '; 
}
