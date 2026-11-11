#include <bits/stdc++.h>
using namespace std;

const int N=5e5+5,M=3e5+5;

int n,m;
int a[N];
int g[N];
int ans[M];
int t;

void Init(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
}

void solve(){
	t=0;
	for(int num=0;num<n;num++){
		memset(g,0,sizeof(g));
		for(int i=num;i<n;i++){
			g[t]=a[i];
			for(int j=0;j<t-1;j++){
				int temp=g[0];
				if(g[j]==g[t]){
					t=j;
					break;
				}
			}
			t++;
		}
		for(int i=0;i<t;i++){
			int a=g[i];
			ans[a]++;
		}
		t=0;
	}
	
}

void Printf(){
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}

int main(){
	Init();
	solve();
	Printf();
	return 0;
}
//¼ÇµÃÉ¾×¢ÊÍ 
