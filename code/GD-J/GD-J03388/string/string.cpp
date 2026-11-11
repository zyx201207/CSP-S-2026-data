#include<iostream>
#include<stdio.h>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
using namespace std;
struct Pair{
	int fst;
	char scd;
};
queue<Pair> q;
stack<Pair> stk;
long long ans,check,sum;
int n;
bool out()
{
	if(q.front().fst>stk.top().fst)
	{
		if(check+stk.top().fst>sum/2)
		{
			ans+=sum/2-check;
			return true;
		}
		check+=stk.top().fst;
		ans+=stk.top().fst;
		q.front().fst-=stk.top().fst;
		stk.pop();
		return false;
	}
	if(q.front().fst<stk.top().fst)
	{
		if(check+q.front().fst>sum/2)
		{
			ans+=sum/2-check;
			return true;
		}
		check+=q.front().fst;
		ans+=q.front().fst;
		stk.top().fst-=q.front().fst;
		q.pop();
		return false;
	}
	if(check+q.front().fst>sum/2)
	{
		ans+=sum/2-check;
		return true;
	}
	check+=q.front().fst;
	ans+=q.front().fst;
	q.pop();
	stk.pop();
	return false;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char c;
		cin>>x>>c;
		q.push({x,c});
		stk.push({x,c});
		sum+=x;
	}
	while(1)
	{
		
		if(q.front().scd==stk.top().scd)
		{
			long long tmp=ans;
			bool b=out();
			ans=tmp;
			if(b)break;
		}
		else
		{
			if(out())break;
		}
	}
	cout<<ans;
} 
