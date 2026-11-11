//我是秦始皇，我还没有死，这道题目给我AC，我封你做AC大将军 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200002];
int andw[200002];
int andr[200002];
//int dp[2001][2001];
int ans;
int f1=1,f2=1,f3=1;
void dfs(int i,int res,int cnt){
	if(i==n+1){
		if(cnt==m)
			ans=max(ans,res);
		return;
	}
	if(cnt==0){
		dfs(i+1,a[i],cnt+1);
		dfs(i+1,0,cnt);
	}else{
		dfs(i+1,res&a[i],cnt+1);
		dfs(i+1,res,cnt);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=20){
//		cout<<"         "<<1;
		dfs(1,0,0);
		cout<<ans;
	}else if(n<=2000){
//		cout<<"         "<<2;
		if(m==1){
			cout<<a[n];
		}else if(m==n){
			ans=a[1];
			for(int i=2;i<=n;i++){
				ans&=a[i];
			}
			cout<<ans;
		}else if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					ans=max(ans,a[i]&a[j]);
				}
			}
			cout<<ans;
		}
	}else{
//		cout<<"         "<<3;
		if(m==n-1){
			andw[n+1]=INT_MAX;
			for(int i=n;i>=1;i--){
				andw[i]=andw[i-1]&a[i];
			}
			andr[0]=INT_MAX;
			for(int i=1;i<=n;i++){
				andr[i]=andw[i-1]&a[i];
			}
			for(int i=1;i<=n;i++){
				ans=max(ans,andr[i-1]&andw[i+1]);
			}
		}else{
//		cout<<"         "<<3;
			for(int i=1;i<=n;i++){
				if(a[i]>=4)f1=0;
				int t=a[i]+1;
				while(t){
					if(t%2==1){
						f2=0;break;
					}
					t/=2;
				}
				if(a[i]!=i-1){
					f3=0;
					cout<<i<<endl;
				}
			}
			if(f2){
				cout<<a[n-m+1];
			}else if(f1){
				int cnt0=0,cnt1=0,cnt2=0,cnt3=0;
				for(int i=1;i<=n;i++){
					if(a[i]==0){
						cnt0++;
					}
					if(a[i]==1){
						cnt1++;
					}
					if(a[i]==2){
						cnt2++;
					}
					if(a[i]==3){
						cnt3++;
					}
				}
				if(cnt3>=m){
					cout<<3;
				}else if(cnt3+cnt2>=m){
					cout<<2;
				}else if(cnt3+cnt1>=m){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(f3){
				cout<<n-m<<endl;
			}else{
				cout<<0<<endl;
			}
		}
	}
	return 0;
}

