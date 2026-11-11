#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005],p[500005],nxt[500005],s[500005],tp,xi[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(n<10000){
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		p[j]=0;
		for(int j=i;j<=n;j++)
		nxt[j]=j+1;
		for(int j=i;j<=n;j++)
		{
		if(p[a[j]]){
			int tmp=p[a[j]];
		for(int k=p[a[j]];k<j;k=nxt[k])
		p[a[k]]=0;
		nxt[tmp-1]=j;
		}
		p[a[j]]=j;
		}
		for(int j=1;j<=m;j++)
		if(p[j])ans[j]++;
	}
	for(int j=1;j<=m;j++)
	cout<<ans[j]<<" ";
	}
	else if(m==1)cout<<n;
	else if(m==2){
		for(int i=1;i<=n;i++)
		ans[a[i]]++;
		ans[a[n]]=n;
		for(int j=1;j<=m;j++)
		cout<<ans[j]<<" ";
	}
	else if(m<=3000){
		int lst=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[i+1])
			tp++,s[tp]=a[i],xi[tp]=i-lst,lst=i;
		}
		for(int i=1;i<=tp;i++)
		{
		for(int j=1;j<=m;j++)
		p[j]=0;
		for(int j=i;j<=tp;j++)
		nxt[j]=j+1;
		for(int j=i;j<=tp;j++)
		{
		if(p[s[j]]){
		int tmp=p[s[j]];
		for(int k=p[s[j]];k<j;k=nxt[k])
		p[s[k]]=0;
		nxt[tmp-1]=j;
		}
		p[s[j]]=j;
		}
		for(int j=1;j<=m;j++)
		if(p[j])ans[j]+=xi[i];
		}
		for(int j=1;j<=m;j++)
		cout<<ans[j]<<" ";
	}
	else {
		for(int i=1;i<=n;i++)
		ans[a[i]]=i;
		for(int j=1;j<=m;j++)
		cout<<ans[j]<<" ";
	}
	return 0;
}
