#include<bits/stdc++.h>

using namespace std;

const int N=5e5+5,M=3e5+5;
int n,m,a[N],ans[M],b[M],mark[M];

void play(int x){
	memset(b,0,sizeof(b));
	memset(mark,0,sizeof(mark));
	int cnt=0;
	for(int i=x;i<=n;i++){
		if(mark[a[i]]==0){
			b[++cnt]=a[i];
			mark[a[i]]=cnt;
		}
		else{
			while(cnt>mark[a[i]]){
				mark[b[cnt]]=0;
				cnt--;
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		ans[b[i]]++;
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		play(i);
	}
	for(int i=1;i<=m;i++) cout<<a[m]<<' ';
	return 0;
} 
