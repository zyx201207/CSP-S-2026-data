#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,maxx,ans,all=INT_MAX;
int a[N];
int num[35],js[35];
int dfs(int id,int cnt,int num){
	if(cnt==m) return num;
	if(id==n+1) return -1;
	int p1=dfs(id+1,cnt,num);
	int p2=dfs(id+1,cnt+1,num&a[id+1]);
	return max(p1,p2);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	num[0]=1;
	for(int i=1;i<=31;i++){
		num[i]=num[i-1]*2;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		all=(all&a[i]);
	}
	if(n<=20){
		cout<<max(dfs(1,0,INT_MAX),dfs(1,1,a[1]))<<endl;
	}
	else if(n<=2000){
		if(m==1){
			cout<<maxx<<endl;
		}
		if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					ans=max(ans,a[i]&a[j]);
				}
			}
			cout<<ans<<endl;
		}
		if(m==n){
			cout<<all<<endl;
		}
	}
	else{
		if(m==n-1){
			for(int i=1;i<=n;i++){
				int p=a[i];
				for(int i=30;i>=0;i--){
					if(p>num[i]){
						p-=num[i];
						js[i]++;
					}
				}
			}
			for(int i=30;i>=0;i--){
				if(js[i]>0) ans+=num[i];
			}
			int res=ans,res2=0;
			for(int i=1;i<=n;i++){
				ans=res;
				int p=a[i];
				for(int i=30;i>=0;i--){
					if(p>num[i]){
						p-=num[i];
						if(js[i]==1){
							ans-=num[i];
						}
					}
				}
				res2=max(res2,ans);
			}
			cout<<res2<<endl;
		}
	}
	return 0;
}
