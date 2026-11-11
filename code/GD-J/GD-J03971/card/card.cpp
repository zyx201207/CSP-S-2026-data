#include <bits/stdc++.h>
#define endl '\n'
#define int unsigned long long
using namespace std;
int n,m,st=1,a[500005],ans[300005];
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	n=read(),m=read();
	bool f=1;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]<a[i-1])f=0;
		if(a[i]==a[i-1]&&st!=-1)st=i-1;
		else st=-1;
	}
	if(st==-1)st=1;
	else for(int i=1;i<=st-1;i++)for(int j=st+1;j<=n;j++)ans[a[j]]++;//B
	if(f){//A
		for(int i=1;i<=n;i++)ans[a[i]]++;
		for(int i=1;i<=m;i++)ans[i]+=ans[i-1],cout<<ans[i]<<" ";
		//cout<<endl<<"man";
		return 0;
	}
	for(int i=st;i<=n;i++){
		vector<int>v,d(m+5,0);
		for(int j=i;j<=n;j++){
			if(d[a[j]]){
				int len=v.size(); 
				for(int k=len-1;k>=d[a[j]];k--){
					d[v[k]]=0;
					if(v.size()>0)v.pop_back();
				}
			}else{
				v.push_back(a[j]),d[a[j]]=v.size();
			}
		}
//		for(auto &x:v)cout<<x<<" ";
//		cout<<endl;
		for(auto &x:v)ans[x]++;
		v.clear(),vector<int>().swap(v);
		d.clear(),vector<int>().swap(d);
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
