#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PIS pair<int,char>
const int N=1e5+10;
int a[N];
char s[N];
int n;
int cnt,cn,idx=1;
PIS b[N];
stack<PIS> st;
int ans;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>n;
	
	for(int i=1;i<=n;i++){cin>>a[i];cin>>s[i];cnt+=a[i];}
	for(int i=1;i<=n;i++)
	{
		cn+=a[i];
		if(cnt%2&&cn>cnt/2&&cn-a[i]<=cnt/2){a[i]--,cnt--,cn--;}
		if(a[i]<=0)continue;
		if(s[i]==s[i-1])b[idx-1].first+=a[i];
		else b[idx++]={a[i],s[i]};
		
	}
	
	cn=0;int t=0;
	for(int i=1;i<idx;i++)
	{
		cn+=b[i].first;
		if(cn<=cnt/2)
		{
			st.push(b[i]);
		}
		else
		{
			if(cn-b[i].first<=cnt/2)
			{
				int l=cnt/2-cn+b[i].first,r=b[i].first-l;
				if(l>r)st.push({l-r,s[i]});
				else{
					while(r-l>0&&!st.empty())
					{
						auto it=st.top();st.pop();
						if(it.second!=s[i])ans+=min(r-l,it.first);
						if(it.first>r-l)st.push({it.first-r+l,it.second});
						else r-=it.first;
					}
				}
			}
			else
			{
				int len=b[i].first;
				while(len>0&&!st.empty())
				{
					auto it=st.top();st.pop();
					if(it.second!=s[i])ans+=min(len,it.first);
					if(it.first>len)st.push({it.first-len,it.second});
					else len-=it.first;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}