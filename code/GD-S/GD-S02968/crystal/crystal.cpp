#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define ciallo continue
using namespace std;
inline int read(){
	char c=getchar();
	int res=0,f=1;
	while(!isdigit(c)){
		if(c=='-') f*=-1;
		c=getchar();
	}while(isdigit(c)){
		res=res*10+c-48;
		c=getchar();
	}
	return res*f;
}
const int N=5e5+10;
int n,m,ans=1;
int a[N];
int idx=0,suv=0,cnt=0;
vector<PII> v;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	a[0]=LLONG_MAX;
	for(int i=1;i<=n+1;i++){
		if(a[idx]!=a[i]){
			if(a[idx]!=LLONG_MAX){
				v.push_back({a[idx],suv});
				cnt++;
			}
			idx=i;
			suv=1;
		}else{
			suv++;
		}
	}
	for(int i=0;i<cnt;i++){
		int w=m,u=i,res=v[i].second;
		while(w>0&&u>0){
			u--;
			int dis=v[i].first-v[u].first;
			if(w>=dis){
				int lm=min(w/dis,v[u].second);
				res+=lm;
				w-=lm*dis;
			}else{
				break;
			}
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
}
