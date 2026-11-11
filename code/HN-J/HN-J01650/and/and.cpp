#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define MAX(x,y) (x)=max((x),(y))
#define MIN(x,y) (x)=min((x),(y))
const int N=2e5+5;
int a[N],n,m;
int ans=0;
bool vis[N];
void dfs(int level,int sum){
	if(sum<=ans) return;
	if(level>m){
		ans=sum;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		dfs(level+1,sum&a[i]);
		vis[i]=0;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1,(1<<30)-1);
		cout<<ans<<endl;
		return 0;
	}
	if(n<=2000){
		if(m==1){
			for(int i=1;i<=n;i++){
				MAX(ans,a[i]);
			}
			cout<<ans<<endl;
			return 0;
		}
		if(m==2){
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					MAX(ans,(a[i]&a[j]));
				}
			}
			cout<<ans<<endl;
			return 0;
		}
		if(m==n){
			ans=a[1];
			for(int i=2;i<=n;i++){
				ans&=a[i];
			}
			cout<<ans<<endl;
			return 0;
		}
	}
	if(m==n-1){
		int bit[30]={};
		for(int i=1;i<=n;i++){
			for(int j=0;j<30;j++){
				if((a[i]>>j)&1) bit[j]++;
			}
		}
		for(int i=1;i<=n;i++){
			int sum=0;
			for(int j=0;j<30;j++){
				if((a[i]>>j)&1) bit[j]--;
				if(bit[j]==m) sum|=(1<<j);
			}
			MAX(ans,sum);
			for(int j=0;j<30;j++){
				if((a[i]>>j)&1) bit[j]++;
			}
		}
		cout<<ans<<endl;
	}
	bool subtask1=1,subtask2=(n-(n&-n)==0);
	int max_=0;
	for(int i=1;i<=n;i++){
		int text=a[i]+1;
		if(text-(text&-text)!=0) subtask1=0;
		if(a[i]!=i-1) subtask2=0;
		MAX(max_,a[i]);
	}
	if(subtask1){
		int bit[30]={};
		for(int i=1;i<=n;i++){
			for(int j=0;j<30;j++){
				if((a[i]>>j)&1) bit[j]++;
				if(bit[j]>=m) ans|=(1<<j);
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	if(subtask2){
		int k=0;
		while(n){
			n>>=1;
			k++;
		}
		k-=2;
		for(int i=k;i>=0;i--){
			if(m<=(1<<i)){
				ans|=(1<<i);
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	for(int i=max_;i>=0;i--){
		int sum=0;
		for(int j=1;j<=n;j++){
			if((i&a[j])==i) sum++;
		}
		if(sum>=m){
			ans=i;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
