#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;

int n,m,a[N],ans=-1,vis[N];
void slove1(int num,int zhi){
	if(num>m){
		ans=max(ans,zhi);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			slove1(num+1,(zhi&a[i]));
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		slove1(1,-1);
		cout<<ans;
	}else if(n<=2000){
		if(m==1){
			for(int i=1;i<=n;i++)ans=max(ans,a[i]);
			cout<<ans;
		}else if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j)continue;
					ans=max(ans,(a[i]&a[j]));
				}
			}
			cout<<ans;
		}else if(m==n){
			for(int i=1;i<=n;i++)ans&=a[i];
			cout<<ans;
		}else{
			slove1(-1,1);
			cout<<ans;
		} 
	}else{
		slove1(-1,1);
		cout<<ans;
	}

	return 0;
}
// 预计过 1~10 测试点 
//预计分数 40 
