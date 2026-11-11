#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int N =2e5+5;

long long len[N];
char s[N];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ans = 0;
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> len[i] >> s[i];
	}	
	
	queue< pair<char,long long> > l,r;
	int lp=0,rp=n+1,mid = (n+1)/2;
	
	l.push({s[++lp],len[lp]});
	r.push({s[--rp],len[rp]}) ;
	
	while( (!l.empty()) || (!r.empty()) )
	{
		if(l.empty() || r.empty()) break;
		pair<char,long long> a = l.front();
		l.pop();
		pair<char,long long> b = r.front();
		r.pop();
		
//		cout << a.first << ' ' << a.second<< ' ' << b.first << ' ' << b.second << endl;
			if(a.second>b.second)
			{
				if(a.first!=b.first) ans+=b.second; 
				l.push({a.first,a.second-b.second});
			}else if(a.second<b.second)
			{
				if(a.first!=b.first)ans+=a.second;	
				r.push({b.first,b.second-a.second});
			}else
			{
				if(a.first!=b.first)ans+=a.second;
			}
		
		if(lp<rp-1 && l.empty())
		l.push({s[++lp],len[lp]});
		if(rp>lp+1 && r.empty())
		r.push({s[--rp],len[rp]}) ;
	}
	
//	cout << l.empty();
	cout << ans;
	return 0;
}
