#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
const long long INF=1e16+7;
int n,m;
int cnt[maxn];
int t[maxn];
long long final_ans;
long long a[maxn],fast[37];
int b2[maxn][34];
void init(long long id){
	long long now=a[id];
	for(int i=34;i>=0;i--){
		if(now>=fast[i]){
			now-=fast[i];
			b2[id][i]=1;
		}
	}
}
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	fast[0]=1;
	for(int i=1;i<=34;i++) fast[i]=fast[i-1]*2;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		init(i);
	}
	for(int i=31;i>=0;i--){
		for(int j=1;j<=n;j++){
			if(b2[j][i]) cnt[j]++;
		}
		for(int j=1;j<=31;j++) t[j]=0;
		for(int j=1;j<=n;j++) t[cnt[j]]++;
		int now=0,tag=0;
		bool fl=false;
		for(int j=31;j>=1;j--){
			if(now+t[j]>=m){
				tag=j;
				fl=true;
				break;
			}
			now+=t[j];
		}
		if(fl){
			int cntt=0;
			long long ans=137438953471;
			for(int j=1;j<=n;j++){
				if(cnt[j]>=tag){
					ans=ans&a[j];
					cntt++;
				}
				if(cntt==m) break;
			}
			final_ans=max(final_ans,ans);
		}	
	}
	cout<<final_ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
