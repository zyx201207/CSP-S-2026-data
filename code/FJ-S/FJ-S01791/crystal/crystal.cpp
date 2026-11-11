#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans=-1,f=1,fl,flag=1,s;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			f=0;
		}
	}
	fl=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=fl){
			flag=0;
			break;
		}
	}
	if(f==1){
		for(int i=0;;i++){
			m-=i;
			if(m<0){
				cout<<i;
				return 0;
			}
			if(i>=n){
				cout<<n;
				return 0;
			}
		}
	}
	if(flag==1){
		m/=fl;
		for(int i=0;;i++){
			m-=i;
			if(m<0){
				cout<<i;
				return 0;
			}
			if(i>=n){
				cout<<n;
				return 0;
			}
		}
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		s=m;
		for(int j=i-1;j>=1;j--){
			s=s-(a[i]-a[j]);
			if(s<0){
				ans=max(i-j,ans);
//				cout<<i<<" "<<j<<endl;
				break;
			}
			if(j==1){
				if(s>=0){
					ans=max(i-j+1,ans);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
