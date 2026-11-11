#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100001],pjs,l,r,ans=1,half,dc;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(m==0){
		cout<<1;
		return 0;
	}
	if(n<=500000){
		if(m==0){
			cout<<1;
			return 0;
		}for(int i=1;i<=n;i++){
			cin>>a[i];
			pjs+=a[i];
		}
		pjs/=n;
		sort(a+1,a+n+1);
		long long x=lower_bound(a+1,a+n+1,pjs)-a;
		l=x;
		r=x;
	//	cout<<x;
		while(m>0){
			if(a[l]-a[l-1]<=a[r+1]-a[r]){
				if(m>=a[l]-a[l-1]){
					ans++;
				}
	//			cout<<a[l]-a[l-1]<<"* "<<endl;
				m-=a[l]-a[l-1];
	//			cout<<m<<"| "<<endl;
				a[l-1]=a[l];
	//			cout<<a[l-1]<<"N ";
				l--;
			}else{
				if(m>=a[r+1]-a[r]){
					ans++;
					
				}m-=a[r+1]-a[r];
				a[r+1]=a[r];
				r++;
			}
		}
		cout<<ans;
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dc=a[2]-a[1];
		pjs=n/2+1;
		half=m;
		while(half){
			if(half>=dc){
				ans++;
				half-=dc;
				if(half>=dc){
					ans++;
					half-=dc;
				}
				dc*=2;
			}else{
				break;
			}
		}
		cout<<ans;
	}
		
	return 0;
}
