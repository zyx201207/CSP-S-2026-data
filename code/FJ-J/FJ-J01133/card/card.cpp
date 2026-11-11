#include<bits/stdc++.h>
using namespace std;
const int MAXN=(int)(5e5+10);//请确定数组大小!!!
int a[MAXN],wei[MAXN],ans[MAXN],cnt[MAXN],fa[MAXN],out[MAXN];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);//请确认文件名（尤其是输出）
	//不要开头就写xxx3.out，有可能覆盖文件
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=1;i--)
	{
		wei[a[i]]=max(wei[a[i]],i),cnt[a[i]]++;
		if(i==wei[a[i]])
		{
			fa[a[i]]=a[i+1];
			out[a[i+1]]++;
		}
	}
	//for(int i=1;i<=m;i++)cout<<fa[i]<<" \n"[i==m];
	queue<int>q;
	for(int i=1;i<=m;i++)if(!out[i])q.push(i);
	while(q.size())
	{
		int p=q.front();q.pop();
		ans[p]+=cnt[p];
		ans[fa[p]]+=ans[p];
		--out[fa[p]];
		if(!out[fa[p]])
			q.push(fa[p]);
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}


