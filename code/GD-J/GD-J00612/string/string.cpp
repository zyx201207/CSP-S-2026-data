#include <iostream>
#include <deque>

using namespace std;
typedef long long ll;

long long T,ans;
deque<pair<char,long long>> q;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	cin>>T;
	while(T--)
	{
		char a;
		long long b;
		cin>>b>>a;
		q.push_back(make_pair(a,b));
	}
	
	while(q.size()>1)
	{
		pair<char,long long> a=q.front(),b=q.back();
		long long lenc=abs(a.second-b.second);
		q.pop_back();
		q.pop_front();
		ans+=(a.first==b.first?0:min(a.second,b.second));
		if(a.second>b.second) q.push_front(make_pair(a.first,lenc)); 
		if(a.second<b.second) q.push_back(make_pair(b.first,lenc)); 
	}
	cout<<ans;
	return 0;
}

