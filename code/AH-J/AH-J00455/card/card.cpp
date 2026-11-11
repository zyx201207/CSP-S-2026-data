#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[300005],sta[500005],st[300005][2],stt[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,m,fl=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])
		 fl=1;
	}
	if(fl==0){
		for(int i=1;i<=m;i++)
		 cout<<i<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++){
		int len=0;
		memset(stt,0,sizeof stt);
		for(int j=i;j<=n;j++){
			sta[++len]=a[j];
			if(st[a[j]][0]==1){
				for(int k=len;k>st[a[j]][1];k--)
				 st[sta[k]][0]=0;
				len=st[a[j]][1];
			}
			st[a[j]][0]=1;
			st[a[j]][1]=len;
		}
		for(int k=1;k<=len;k++){
			ans[sta[k]]+=!stt[sta[k]];
			stt[sta[k]]=1;
			st[sta[k]][0]=0;
		}
	}
	for(int i=1;i<=m;i++)
	 cout<<ans[i]<<" ";
	return 0;
}
