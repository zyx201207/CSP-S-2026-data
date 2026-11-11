#include<bits/stdc++.h>
using namespace std; 
long long s[500005];
bool v[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	deque<long long> a;
	cin>>n>>m;
	for(long long i=0;i<n;i++)
	{
		long long b;
		cin>>b;
		a.push_back(b);
	}
	long long t=n;
	while(t--)
	{
		cout<<endl;
		deque<long long> q;
		for(long long i=0;i<a.size();i++)
		{
			if(v[a.front()])
			{
				while(q.back()!=a.front())
				{
					a.push_back(q.back());
//					cout<<"////"<<endl<<q.back()<<endl<<"////";
					v[q.back()]=0;
					q.pop_back();
				}
//				q.pop_back();
			}
			else
				v[a.front()]=1;
			q.push_back(a.front());
			a.pop_front();
		}
		memset(v,0,sizeof(v));
//		for(long long i=0;i<a.size();i++)
//			cout<<a[i]<<" ";
		for(int i=0;i<q.size();i++)
			s[q[i]]++;
	}
	cout<<endl;
	for(long long i=1;i<=m;i++)
		cout<<s[i]<<" ";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 3
1 2 1 3
*/
