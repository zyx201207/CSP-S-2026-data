#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,maxn=0,cnt=0,ans=0,res=0,sum=0;
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	if(m==0){                                             
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]){
				cnt++;
				maxn=max(maxn,cnt);
			}else cnt=0;
		}
		cout<<maxn+1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(maxn>n-i){
			break;
		}
//		cout<<"µ±Ç°µÄa[i]"<<a[i]<<'\n';
//		cout<<"maxn"<<maxn<<'\n';
		for(int j=i;j<=n;j++){
			if(a[j]==a[i]){
				sum++;
//				cout<<"sum"<<sum<<"(a[j]==a[i])"<<'\n';
				maxn=max(maxn,sum);
				if(maxn>n){
					cout<<n;
					return 0;
				}
				continue;
			}
			if(a[j]!=a[i]){
				int aa=a[i]-a[j];
				ans+=aa;
//				cout<<"ans"<<ans<<'\n';
				if(ans<=m){
					sum++;
//					cout<<"sum"<<sum<<"(a[j]!=a[i])"<<'\n';
					maxn=max(maxn,sum);
					continue;
				}
				if(ans>m){
					sum=0;
					ans=0;
					break;
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<'\n';
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<'\n';
//		for(int j=i;j<=n;j++){
//			ans=0;
//			if(a[j]==a[i]){
//				sum++;
//				cout<<"sum"<<sum<<'\n';
//				cout<<j<<'\n';
//				maxn=max(maxn,sum);
//				if(maxn>n){
//					cout<<n;
//					return 0;
//				}
//				continue;
//			}
//			else if(a[j]!=a[i]){
//				cout<<"sum"<<sum<<'\n';
//				ans+=(a[i]-a[j]);
//				cout<<"ans"<<ans<<'\n';
//				if(ans<=m){
//					sum++;
//					maxn=max(maxn,sum);
//			    }
//			}
//			 if(ans>m){
//				sum=0;
//				//ans=0;
//				continue;
//			}
//		}
//	}
	cout<<maxn;
	return 0;
}

//9 8 4 2 1


