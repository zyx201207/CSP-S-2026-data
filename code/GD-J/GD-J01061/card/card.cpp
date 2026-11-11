#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],ans[300001],wz;
int xb[300001],xb2[300001];
deque<int> que,que2;
int main()
{
//	memset(xb,false,sizeof(xb));
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),xb[a[i]]=false;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(xb[a[j]])
			{
				while(!que.empty()&&que.back()!=a[j]) xb[que.back()]=false,que.pop_back();
			}
			else que.push_back(a[j]),xb[a[j]]=true;
		}
		while(!que.empty())
		{
			ans[que.front()]++;
			xb[que.front()]=false;
			que.pop_front();
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
/*

//		if(xb[a[i]])
//		{
//			cout<<"|	";
//		}
//		else
//		{
//			xb[a[i]]=true;
//			que.push_front(a[i]);
//			cout<<"-	";
//		}
//		for(int j=que.size();j>=1;j--)
//		{
//			cout<<que.front()<<" ";
//			que.push_back(que.front());
//			ans[que.front()]++;
//			que.pop_front();
//		}
//		cout<<"|"<<a[i]<<" "<<que.size()<<" "<<i-1<<"\n";
*/
