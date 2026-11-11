#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct node{
	int data;
	node *next;
	node(int val):data(val),next(nullptr){};
}*map;
void push(int val)
{
	node *newnode=new node(val);
	if(map==nullptr)
	{
		map=newnode;
		return;
	}
	node *current=map;
	while(current->next!=nullptr)
	{
		if(current->data==newnode->data)
		{
			current->next=nullptr;
			return;
		}
		current=current->next;
	}
	current->next=newnode;
}
void prinf()
{
	node *current=map;
	while(current!=nullptr)
	{
		cout<<current->data<<" ";
		current=current->next;
	}
	cout<<endl;
}
int f[300005];
void count()
{
	node *current=map;
	while(current!=nullptr)
	{
		f[current->data]++;
		current=current->next;
	}
}
int n,m;
int a[500005];
void solve(int x)
{
	for(int j=x;j<=n;j++) 
		push(a[j]);
	count();
	map=nullptr;
}
int dff[300005];
int cnt[300005];
vector<int> strat(m+1);
vector<vector<int>> dp(n+1,strat);
void countb(int x)
{
	node *current=map;
	while(current!=nullptr)
	{
		dp[x][current->data]++;
		current=current->next;
	}
}
void solveb(int x)
{
	for(int j=x;j<=n;j++) 
		push(a[j]);
	countb(a[x]);
	map=nullptr;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dff[a[i]]=i;
		cnt[a[i]]++;
	}
	if(n<=5000)
	{
		for(int i=1;i<=n;i++) solve(i);
		for(int i=1;i<=m;i++)
			cout<<f[i]<<" ";
		cout<<"\n";
	}
	else
	{
		for(int i=1;i<=m;i++)
			for(int j=dff[i];j<=m;j++)
				solveb(j);
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				f[i]=cnt[j]*dp[j][i];
		for(int i=1;i<=m;i++)
			cout<<f[i]<<" ";
		cout<<"\n";
	}
	return 0;
}
