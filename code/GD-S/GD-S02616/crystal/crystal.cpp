#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500009],n,m,cha=0,f=1,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(cha!=0&&i>0){
			cha=abs(a[i-1]-a[i]);
		}
		if(i>1&&cha!=abs(a[i-1]-a[i])){
			f=0;
		}
	}
	if(f){
		ll k=0,i;
		for(i=1;k+i*cha<m;i++)k+=i*cha;
		cout<<i;
	}else{
		sort(a+1,a+n+1);
		for(ll i=2;i<n;i++){
			ll l=i-1,r=i+1,k=m,si=a[i],len=1;
			while(k>=si-a[l]&&k>=abs(a[r]-si)*len){
				if(si-a[l]<len*(a[r]-si)&&k>=si-a[l]){
					k-=(si-a[l]);
					len++;
					if(l-1>=1){
						l--;
					}else{
						break;
					}
				}else{
					k-=len*(a[r]-si);
					si=a[r];
					len++;
					if(r+1<=n){
						r++;
					}else{
						break;
					}
				}
			}
			if(l==1){
				while(r<=n&&k>=abs(a[r]-si)*len){
					k-=len*(a[r]-si);
					si=a[r];
					len++;
					r++;
				}
			}else{
				while(l>=1&&k>=si-a[l]){
					k-=(si-a[l]);
					len++;
					l--;
				}
			}
			ans=max(ans,len);
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
