#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int qread()
{
	char c=getchar();
	int x=0,f=1;
	for(;!isdigit(c);c=getchar())if(c=='-')f*=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	return x*f;
}

vector<int>t;
vector<int>w;
int n,d,T,l,r,ans,tp,tp1;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	T=qread();T=qread();
	while(T--)
	{
		n=qread();d=qread();
		t.clear();
		w.clear();
		w.resize(n);
		ans=0;
		for(int p=0;p<n;p++)w[p]=qread();
		for(int p=0;p+3<n;p++)
		{
			if(w[p+3]-w[p+2]<=d&&w[p+3]-w[p+1]<=d&&w[p+2]-w[p]<=d&&w[p+1]-w[p]<=d&&w[p+3]-w[p]>d)t.push_back(p);
		}
		for(int p=0;p<t.size();p++)
		{
			l=t[p];r=t[p]+3;
			while(l>0&&w[l]-w[l-1]<=d&&w[l+1]-w[l-1]>d)l-=1;
			while(r<n-1&&w[r+1]-w[r]<=d&&w[r+1]-w[r-1]>d)r+=1;
			ans+=(t[p]-l+1)*(r-t[p]-2);
		}
		cout<<ans<<endl;
	}
	return 0;
}
