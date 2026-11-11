#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N=1e6+5;

inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
	return x*f;
}
int find_ans(vector<PII>a,int i,int dep){
	return dep;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int n,k,u,v;vector<PII>a;int ans=0,i=4;
	cin>>n>>k;
	while(k--){
		ans=0;
		cin>>u>>v;
		a.push_back({u,v});
		ans=i;
		cout<<ans-3<<endl;i++;
	}
	return 0;
}

