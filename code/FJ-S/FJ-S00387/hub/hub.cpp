#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=1e9;
inline int qread()
{
	char c=getchar();
	int x=0,f=1;
	for(;!isdigit(c);c=getchar())if(c=='-')f*=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	return x*f;
}
struct node
{
	int num;
	vector<int>to;
};
bool cmp(pair<int,int>a,pair<int,int>b)
{
	if(a.first==b.first)return a.second>b.second;
	return a.first>b.first;
}
vector<node>w;
vector<int>us;
vector<int>ans;
vector<pair<int,int> > t;
bool find(int a,int b)
{
	for(int p=0;p<w[a].to.size();p++)
	{
		if(w[a].to[p]==b)return 1;
	}
	return 0;
}
int tp1,tp2,T,n,k,flg;
bool flg1;
void dfs(int root,int dis)
{
	if(ans[root]<dis)return;
	for(int p=0;p<w[root].to.size();p++)
	{
		if(ans[w[root].to[p]]>dis+1)ans[w[root].to[p]]=dis+1,dfs(w[root].to[p],dis+1);
	}
	return ;
}
int main()
{
	//freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);
	T=qread();T=qread();
	while(T--)
	{
		n=qread();
		k=qread();
		flg=0;
		ans.clear();
		us.clear();
		w.clear();
		t.clear();
		w.resize(n);
		t.resize(n);		
		ans.resize(n,inf);
		for(int p=0;p<n;p++)t[p].second=p;
		for(int p=0;p<n-1;p++)
		{
			tp1=qread()-1;
			tp2=qread()-1;
			w[tp1].to.push_back(tp2-1);
			w[tp2].to.push_back(tp1-1);
			t[tp1].first+=1;
			t[tp2].first+=1;
		}
	 	sort(t.begin(),t.end(),cmp);
	 	tp1=0;
	 	for(int p=0;p<k;p++)
	 	{
	 		if(flg!=2)
	 		{
	 			us.push_back(t[p].second);
	 			flg1=0;
	 			for(int q=0;q<us.size();q++)
	 			{
	 				if(find(p,us[q]))flg1=1;	
				}
				if(!flg1)flg+=1;
			}
			else
			{
				flg1=0;
				for(int q=0;q<us.size();q++)
				{
					if(!find(p,us[q]))
					{
						k+=1;
						flg1=1;
						break;
					}
					if(!flg1)us.push_back(t[p].second);
				}
			}
		}
		for(int p=0;p<us.size();p++)
		{
				dfs(us[p],0);
				ans[us[p]]=0;
		}
		tp1=0;
		for(int p=0;p<n;p++)tp1=min(ans[p],tp1);
		cout<<tp1<<endl;

	}
	return 0;
}