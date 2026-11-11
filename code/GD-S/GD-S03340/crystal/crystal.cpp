#include<bits/stdc++.h>
using namespace std;
long long n,m,a[600000],same,sl,ans=0;
bool pd=1;
bool B=1;
long long solve(int x){
	long long l=x-1,r=x+1,m1=m;
	long long absl,absr,cnt=1;
	while(1){
		if(l<1&&r>n)break;
		absl=abs(a[l]-a[x]),absr=abs(a[r]-a[x]);
		if(l<1){
			if(r<=n){
				if(m1>=absr){
					m1-=absr;
					r++;
					cnt++;
				}
				else break;
			
			continue;
			}
			else break;
		}
		if(r>n){
			if(l>=1){
				if(m1>=absl){
					m1-=absl;
					l--;
					cnt++;
				}
				else break;
			
			continue;
			}
			else break;
		}
		if(absl<=absr){
			if(m1>=absl){
				m1-=absl;
				l--;
				cnt++;
			}
			else break;
		}
		if(absl>absr){
			if(m1>=absr){
				m1-=absr;
				r++;
				cnt++;
			}
			else break;
		}
	}
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			same=a[i];
		}
		if(i==2){
			sl=a[i]-a[i-1];
		}
		if(same!=a[i]){
			pd=0;
		}
		if(i>2&&sl!=a[i]-a[i-1]){
			B=0;
		}
	}
	if(pd){
		cout<<n;
	}
	else{
		if(B){
			long long ans=0;
			for(int i=1;m>=i;i++,ans++){
				m-=i;
			}
			ans=min(n,ans);
			cout<<ans;
		}
		else{
			sort(a+1,a+1+n);
			for(int i=1;i<=n;i++){
				ans=max(ans,solve(i));
				
			}
			cout<<ans;
		}
	}
	return 0;
} 
