#include <iostream>
#include <list>

using namespace std;

long long n,m,a[1000010],at[1000010],cnt[1000010];
list<long long>l;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	at[n+1]=a[n+1]=n+1;
	for(long long i=n;i>=1;i--)
	{
		//cerr<<"|"<<i<<endl;
		if(!at[a[i]])at[a[i]]=i;
		for(long long j=at[a[i]];j&&j<=n;)
		{
			//cerr<<"||"<<j<<endl;
			cnt[a[j]]++;
			j=at[a[j+1]];
		} 
		/*
		cerr<<"|"<<i<<endl;
		if(at[a[i]])
		{
			for(list<long long> ::iterator j=l.begin();*j!=a[i];j=l.erase(j))
			{
				cnt[*j]+=at[*j]-i;
				at[*j]=0;
			}
		}
		else
		{
			l.push_front(a[i]);
			at[a[i]]=i;
		}
		cerr<<"l:";for(list<long long> ::iterator i=l.begin();i!=l.end();i++)cerr<<*i<<" ";cerr<<endl;
		*/
	}
	//for(list<long long> ::iterator i=l.begin();i!=l.end();i++)cnt[*i]+=at[*i];
	cout<<cnt[1];
	for(long long i=2;i<=m;i++)cout<<" "<<cnt[i];
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
