#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define down(i,x,y) for(int i=(x);i>=(y);--i)
#define mkp make_pair
#define fi first
#define se second
#define eb emplace_back
#define pb push_back
#define pii pair<int,int>
#define maxn 5005
using namespace std;
int n,m;
int a[500005],last[500005];
bool now[500005];
int pos[maxn][maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		scanf("%d",a+i);
		last[a[i]]=i;
	}
	if(n>5000){
		rep(i,1,m){
			printf("%d",last[i]);
			if(i<m)printf(" ");
		}
		return 0;
	}
	rep(i,1,n){
		rep(j,1,m)now[j]=0;
		stack<int> sta;
		rep(j,i,n){
			if(now[a[j]]){
				while(sta.size()&&sta.top()!=a[j]){
					now[sta.top()]=0;
					sta.pop();
				}
			}else{
				sta.push(a[j]);
				now[a[j]]=1;
			}
		}
		rep(j,1,m){
			if(now[j]){
				pos[j][i]=1;
			}
		}
	}
	rep(i,1,m){
		int ans=0;
		rep(j,1,n){
			ans+=pos[i][j];
		}
		printf("%d",ans);
		if(i<m)printf(" ");
	}
	return 0;
}

