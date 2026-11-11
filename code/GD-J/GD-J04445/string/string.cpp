#include <iostream>
using namespace std;
struct node{long long cnt;char c;}s[200005];
int n,cur;
long long ans;
int main()
{
	ios::sync_with_stdio(false);cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++)
	{
		int a;char b;
		cin >> a >> b;
		if(s[cur].c!=b)
		{
			cur++;
			s[cur]={a,b};
		}
		else s[cur].cnt+=a;
	}
	int l=1,r=cur;
	while(l<r)
	{
//		for(int i = 1;i<=cur;i++)cout << s[i].cnt << ' ' << s[i].c << endl; 
		if(s[l].c==s[r].c)
		{
			if(s[l].cnt==s[r].cnt)
			{
//				cout << "==" << ' ' << l << ' ' << r << endl;
//				s[l].cnt=s[r].cnt=0;
				r--;
				l++;
			}
			else if(s[l].cnt>s[r].cnt)
			{
//				cout << "=l" << ' ' << l << ' ' << r << endl;
				s[l].cnt-=s[r].cnt;
				r--;
			}
			else if(s[l].cnt<s[r].cnt)
			{
//				cout << "=r" << ' ' << l << ' ' << r << endl;
				s[r].cnt-=s[l].cnt;
				l++;
			}
			continue;
		}
		if(s[l].cnt==s[r].cnt)
		{
//			cout << "!=" << ' ' << l << ' ' << r << endl;
//			s[l].cnt=s[r].cnt=0;
			ans+=s[r].cnt;
			r--;
			l++;
		}
		else if(s[l].cnt>s[r].cnt)
		{
//			cout << "!l" << ' ' << l << ' ' << r << endl;
			s[l].cnt-=s[r].cnt;
			ans+=s[r].cnt;
			r--;
		}
		else if(s[l].cnt<s[r].cnt)
		{
//			cout << "!r" << ' ' << l << ' ' << r << endl;
			s[r].cnt-=s[l].cnt;
			ans+=s[l].cnt;
			l++;
		}
	}
	cout << ans;
	return 0;
}
