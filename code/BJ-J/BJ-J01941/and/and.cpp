#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5;
int main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m;
    ll cnt=-1,ans;
    cin>>n>>m;
    vector<ll> a(N);
    cin>>a[1];
    cnt=max(cnt,a[1]);
	for(int i=2;i<=n;i++){
		cin>>a[i];
		cnt=max(cnt,a[i]);
		ans=a[i]&a[i-1];
	}
	if(m==1){
		cout<<cnt;
		return 0;
	}else if(m==n){
		cout<<ans;
		return 0;
	}else if(m==2){
		ll mx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(a[i]&a[j],mx);
			}
		}
		cout<<mx<<"\n";
	}else if(m==3){
		ll mx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					mx=max(a[i]&a[j]&a[k],mx);
				}
			}
		}
		cout<<mx<<"\n";
	}else if(m==4){
		ll mx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						mx=max(a[i]&a[j]&a[k]&a[l],mx);
					}
				}
			}
		}
		cout<<mx<<"\n";
	}else if(m==5){
		ll mx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							mx=max(a[i]&a[j]&a[k]&a[l]&a[o],mx);
						}
					}
				}
			}
		}
		cout<<mx<<"\n";
	}else if(m==6){
		ll mx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								mx=max(a[i]&a[j]&a[k]&a[l]&a[o]&a[p],mx);
							}
						}
					}
				}
			}
		}
		cout<<mx<<"\n";
	}else if(m==n-1){
		ll mi=N;
		for(int i=1;i<=n;i++) {mi=min(mi,a[i]);}
		int aa;
		if(a[1]!=mi) aa=a[1];
		else aa=a[2];
		for(int i=1;i<=n;i++){
			if(a[i]==mi) mi=-1;
			else aa&=a[i];
		}
		cout<<aa<<"\n";
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}


