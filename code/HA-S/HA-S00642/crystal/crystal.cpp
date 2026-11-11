#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,x;
int w[500005],c[500005];
ll ans,cnt1,cnt2;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>w[i];
		if(w[i]==i) cnt1++;
		if(i>1){
			x=w[2]-w[1];
			if(x==w[i]-w[i-1]) cnt2++;
		}
	}
	if(cnt1==n||cnt2==n-1){
		for(int i=1;i<=n;i++){
			if(cnt1==n) c[i]=2*i;
			else if(cnt2==n-1) c[i]=2*(w[n/2]-w[n/2-1]);		
		}
		int p=m;
		for(int i=1;i<=n;i++){
			if(p>=c[i]){
				p-=c[i];
				ans+=2;
			}else if(p>=c[i]/2){
				p-=(c[i]/2);
				ans++;continue;
			}else break;
		}
		cout<<ans;
	}else{
		sort(w+1,w+n+1);
		if(n%2==0){
			int k1=m,k2=m; 
			ll ans1=0,ans2=0;
			int p1=n/2,p2=n/2+1;
			int lef=n/2-1,righ=n/2+1;
			while((k1>=1&&lef>=1)||(k1>=1&&righ<=n)){
				int x1=w[p1]-w[lef],x2=w[righ]-w[p1];
				int sum=x1+x2;
				if(sum<=k1){
			 		k1-=sum;
					lef--;righ++;
					ans1+=2;
				}else{
					if(x1>x2){
						if(k1>=x2){
							k1-=x2;
							ans1++;
							righ++;
						}
					}else{
						if(k1>=x1){
							k1-=x1;
							ans1++;
							lef--;
						}
					}
				}
			}
			int lef2=n/2,righ2=n/2+2;
			while((k2>=1&&lef2>=1)||(k2>=1&&righ2<=n)){
				int x1=w[p2]-w[lef2],x2=w[righ2]-w[p2];
				int sum=x1+x2;
				if(sum<=k2){
					k2-=sum;
					lef2--;righ2++;
					ans2+=2;
				}else{
					if(x1>x2){
						if(k2>=x2){
							k2-=x2;
							ans2++;
							righ2++;
						}
					}else{
						if(k2>=x1){
							k2-=x1;
							ans2++;
							lef2--;
						}
					}
				}
			}
			cout<<max(ans1,ans2);
		}else{
			int p2=n/2+1;
			int lef3=n/2,righ3=n/2+2;
			while((m>=1&&lef3>=1)||(m>=1&&righ3<=n)){
				int x1=w[p2]-w[lef3],x2=w[righ3]-w[p2];
				int sum=x1+x2;
				if(sum<=m){
					m-=sum;
					lef3--;righ3++;
					ans+=2;
				}else{
					if(x1>x2){
						if(m>=x2){
							m-=x2;
							ans++;
							righ3++;
						}
					}else{
						if(m>=x1){
							m-=x1;
							ans++;
							lef3--;
						}
					}
				}
			}
			cout<<ans;
		}
	}
return 0;
}
