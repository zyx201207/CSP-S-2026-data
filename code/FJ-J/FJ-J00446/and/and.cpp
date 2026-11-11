#include<bits/stdc++.h>
using namespace std;
long long p2[32];
bool bi[200010][32];
bool ch[200010];
int jt[32];
int n,m,maxj=-1,maxjj=-1;
long long ans=0;
long long num;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(bi,0,sizeof(bi));
	memset(jt,0,sizeof(jt));
	memset(ch,0,sizeof(ch));
	p2[0]=1;
	for(int i=1;i<=30;i++){
		p2[i]=p2[i-1]*2;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num;
		for(int j=30;j>=0;j--){
			if(p2[j]<=num){
				jt[j]++;
				maxjj=max(maxjj,j);
				bi[i][j]=1;
				num-=p2[j];
			}
			if(num==0) break;
		}
	}
	for(int j=maxjj;j>=0;j--){
		if(jt[j]>=m){
			maxj=j;
			break;
		}
	}
	if(maxj>=0){
		ans+=p2[maxj];
		for(int i=1;i<=n;i++){
			if(bi[i][maxj]){
				ch[i]=1;;
			}
		}
		for(int j=maxj-1;j>=0;j--){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(ch[i] && bi[i][j]) cnt++;
			}
			if(cnt>=m){
				ans+=p2[j];
				for(int i=1;i<=n;i++){
					if(ch[i] && !bi[i][j]){
						ch[i]=0;				
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
