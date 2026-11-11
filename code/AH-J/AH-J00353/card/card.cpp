#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
struct node{
	int num,id;
} a[MAXN],b[MAXN];int front[MAXN],ans[MAXN];
bool f[MAXN],fl[MAXN];
//int back[MAXN];
bool cmp(node x,node y){
	if(x.num==y.num)  return x.id<y.id;
	else  return x.num<y.num;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].num);
		a[i].id=i;
		b[i]=a[i];
	}
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(b[i-1].num==b[i].num)  front[b[i].id]=b[i-1].id;
		else  front[b[i].id]=-1;
//		if(b[i+1].num==b[i].num)  back[b[i].id]=b[i+{}1].id;
//		else  back[b[i].id]=-1;
	}
	for(int i=1;i<=n;i++)
	{
		memset(f,0,sizeof f);
		memset(fl,0,sizeof fl);
		stack<node> q;
		for(int j=i;j<=n;j++)
		{
			if(front[j]>=i&&!fl[front[j]])
			while(q.size()&&q.top().num!=a[j].num)
			{
				fl[q.top().id]=1;
				q.pop();
			}
			q.push(a[j]);
		}
		while(q.size())
		{
			f[q.top().num]=1;
			q.pop();
		}
		for(int j=1;j<=m;j++)  ans[j]+=f[j];
	}
//	for(int i=1;i<=n;i++)  cout<<front[i]<<" ";
//	cout<<"\n";
	for(int i=1;i<=m;i++)  printf("%d ",ans[i]);
	return 0;
}

