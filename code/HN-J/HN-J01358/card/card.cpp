#include<bits/stdc++.h>
using namespace std;
#define MAXN 500010
int n,m,a[MAXN],ans[MAXN];

inline void read(int &x){
	char ch=getchar();int f=1;x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
	x*=f;
}

void fileIO(const string& s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int pos[MAXN];
vector<int> dp[MAXN];
void solve(int x){
	if(!pos[a[x]]){
		dp[x].push_back(a[x]);
		for(int cur:dp[x+1])dp[x].push_back(cur);
	}
	else dp[x]=dp[pos[a[x]]];
	pos[a[x]]=x;
	for(int cur:dp[x])ans[cur]++;
}

int main(){
	fileIO("card");
	read(n);read(m);
	for(int i=1;i<=n;i++)read(a[i]);
	
	for(int i=n;i>=1;i--)solve(i);
	
	for(int i=1;i<=m;i++){
	    printf("%d",ans[i]);
	    if(i!=m)printf(" ");
	}
	return 0;
}
