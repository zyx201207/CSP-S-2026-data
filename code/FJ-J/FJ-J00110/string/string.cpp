#include<bits/stdc++.h>
using namespace std;
#define int long long
#define i64 __int128_t
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
using pii=pair<int,int>;
int dx[5]={0,0,0,1,-1};
int dy[5]={0,1,-1,0,0};
const int mod=1e9+7;
int pows(int a,int b)
{
	int ret=1;
	while(b){
		if(b&1)ret=ret*a;
		a=a*a;
		b>>=1;
	}
	return ret;
}
void Dddd()
{
	int n;
	cin>>n;
	deque<pii>q;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		int ai;
		char ch;
		cin>>ai>>ch;
		sum+=ai;
		q.push_back({ai,ch});	
	}
//	cout<<"sum£º"<<sum<<endl;
	int cnt=0,s=0;
	while(!q.empty())
	{
		if(s>=sum)break;
		auto l=q.front();
		auto r=q.back();
		q.pop_front();
		q.pop_back();
//		cerr<<"l£º"<<l.first<<" "<<(char)l.second<<endl;
//		cerr<<"r: "<<r.first<<" "<<(char)r.second<<endl;		 
		if(l==r) 
		{
			s+=l.first;
			continue;
		}
		s+=l.first+r.first;
		if(l.second==r.second)
		{
			if(l.first>r.first)
			{
				q.push_front({l.first-r.first,l.second});
			}
			else
			{
				q.push_back({r.first-l.first,l.second});
			}
		}
		else
		{
			if(l.first==r.first)
			{
				cnt+=l.first;
				continue;	
			}
			else
			{
				if(l.first>r.first)
				{
					q.push_front({l.first-r.first,l.second});
					cnt+=r.first;
				}
				else
				{
					q.push_back({r.first-l.first,r.second});
					cnt+=l.first;
				}
			}
		}
//		cout<<" s:"<<s<<endl;
	}
	cout<<cnt<<endl;
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int num=1;
//	cin>>num;
	while(num--)
	{
		Dddd();
	}
	return 0;
}

