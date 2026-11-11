//GZ-S00328  贵州师范大学云岩实验中学   田欣愉 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=5e5+10;
int a[N],b[N];
int s,t,idx;
int tt,ans,g,yy;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>5000&&m>100000000&&a[n]>100000){
		for(int i=n;i>=1;i--){
			if(a[i]==i){
				tt+=a[n]-a[i];
				ans++;
				if(tt==m){
					cout<<ans+1;
				}else if(tt>m){
					cout<<ans;
				}	
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i+1]-a[i]==a[i]-a[i-1]){
				g=a[i]-a[i-1];
				g=m/g;
				yy+=i;
				ans++;
				if(g==yy){
					cout<<ans;
				}else if(yy>g){
					cout<<ans-1;
				}			
			}
		}	
	}else{
		sort(a+1,a+n+1);
		for(int i=n;i>=1;i--){
			if(a[i]==i){
				tt+=a[n]-a[i];
				ans++;
				if(tt==m){
					cout<<ans+1;
					return 0;
				}else if(tt>m){
					cout<<ans;
					return 0;
				}	
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i+1]-a[i]==a[i]-a[i-1]){
				g=a[i]-a[i-1];
				g=m/g;
				yy+=i;
				ans++;
				if(g==yy){
					cout<<ans;
					return 0;
				}else if(yy>g){
					cout<<ans-1;
					return 0;
				}			
			}
			for(int i=1;i<=n;i++){
				s+=a[i];
			}
			s/=n;
			int minn=INT_MAX;
			for(int i=1;i<=n;i++){
				if(minn>abs(a[i]-s)){
					minn=abs(a[i]-s);
					t=a[i];
					idx=i;
				}
			}
			for(int i=1;i<=n;i++){
				b[i]=abs(t-a[i]);
				tt+=b[i];
				ans++;
				if(tt==m){
					break;	
				}
			}
			for(int i=1;i<=n;i++){
				if(a[i]==t){
					ans++;
				}
			}
			cout<<ans;		
		}
	} 
	return 0;
} 
