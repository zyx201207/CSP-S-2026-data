#include<bits/stdc++.h>
using namespace std;
int a[200026];
int n,m,ans=-1,maxn=-1;
bool flag=1;
int res=2147483647;
void dfs(int x,int y){
	if(x>n){
		if(y==0){
			ans=max(ans,res);
		}
		return;
	}
	int tmp=res;
	if(y>0){
		res=res&a[x];
		dfs(x+1,y-1);
		res=tmp;
	    dfs(x+1,y);
	}
	else{
		res=tmp;
	    dfs(x+1,y);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) flag=0;
		maxn=max(a[i],maxn);
	}
	if(n<=2000){
		dfs(1,m);
		cout<<ans<<"\n";
		return 0;
	}
	else{
		if(maxn<=4){
			int cnt0=0,cnt1=0,cnt2=0,cnt3=0,cnt4=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0) cnt0++;
				if(a[i]==1) cnt1++;
				if(a[i]==2) cnt2++;
				if(a[i]==3) cnt3++;
				if(a[i]==4) cnt4++;
				if(cnt4>=m) cout<<4<<"\n";
				else{
					if(cnt3>=m) cout<<3<<"\n";
					else{
						if(cnt3+cnt2>=m) cout<<2<<"\n";
						else{
							if(cnt3+cnt1>=m) cout<<1<<"\n";
							else cout<<0<<"\n";
						}
					}
				}
				return 0;
			}
		}
		else if(flag){
			int ans=2147483647;
			for(int i=n;i>=n-m+1;i--){
				ans=ans&a[i];
			}
			cout<<ans<<"\n";
		}
		else{
			int minn=2147483647;
			for(int i=1;i<=n;i++){
				minn=min(a[i],minn);
			}
			cout<<minn<<"\n";
			return 0;
		}
	}
	return 0;
}
