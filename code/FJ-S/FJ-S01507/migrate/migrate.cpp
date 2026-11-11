//CSP-S AK me
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000005;
int c,t,n,d,x[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//sorry,you only can find the worst solution.
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(c==11 || c==12){
			int dd=x[2]-x[1];
			d/=dd;
			if(d>=2) cout<<max(0ll,n-(2*d-1))<<"\n";
			else cout<<"0\n";
		}else{
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					int cnt=0;
					for(int s=0;s<(1<<(j-i-1));s++){
						int tmp=x[i],flg=1;
						s<<=1,s|=1;
						for(int k=0;k<(j-i+1);k++){
							if((s>>k)&1){
								if(x[i+k]-tmp<=d){
									tmp=x[i+k];
								}else{
									flg=0;
									break;
								}
							}
						}
						if(flg) cnt++;
					}
					if(cnt==2) ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
} 
//10 3
//-1000000000000000000
//-999999999999999997
//-999999999999999994
//-999999999999999993
//-999999999999999992
//-999999999999999991
//-999999999999999990
//-999999999999999989
//-999999999999999986
//-999999999999999983
//9
