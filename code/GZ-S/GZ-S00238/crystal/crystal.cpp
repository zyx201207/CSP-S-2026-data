//GZ-S00238 吴倬然 贵州师范大学云岩实验中学 
#include<bits/stdc++.h>
using namespace std;

map<long long,long long> mp;
long long n,m,a[500005],cnt,t=1,ans,s[500005],sum[500005],d,f,o[5005][5005];
double p,z;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1; i<=n; i++){
		cin>>a[i];
		s[i]=a[i];
		mp[a[i]]++;
	}	
	sort(a+1,a+n+1); 
	if(n<=5000){
		for(long long i=1; i<n; i++){
			o[i][i+1]=a[i+1]-a[i];
		} 
		for(long long i=1; i<=n; i++){
			for(long long j=i+2; j<=n; j++){
				o[i][j]=o[i][j-1]+(a[j]-a[j-1])*(j-i);
			}
		}
		for(long long i=1; i<=n; i++){
			for(long long j=1; j<i; j++){
				if(o[j][i]<=m){
					ans=max(ans,i-j+1);
				}
			}
		}
		cout<<ans;
		return 0;
	}
	else{
		for(long long i=2; i<=n; i++){
			if(i==2){
				d=a[i]-a[i-1];
			}
			if(i!=2&&d!=a[i]-a[i-1]){
				f=1;
			}
		}
		if(!f){
			cnt=d;
			ans=1;
			while(m>=0){
				if(m>cnt){
					m-=cnt;
					ans++;
					cnt+=d;
				}
				else break;
			} 
			cout<<ans;
			return 0;
		}
		for(long long i=1; i<=n; i++){
			s[i]/=mp[a[i]];
			cnt+=s[i];
		}
		if(m==0){
			for(long long i=1; i<=n; i++){
				ans=max(ans,mp[a[i]]);
			} 
			cout<<ans;
			return 0;
		} 
		p=cnt/n;
		z=abs(p-a[1]);
		for(long long i=2; i<=n; i++){
			if(z>abs(p-a[i])||(z==abs(p-a[i])&&mp[a[i]]>mp[a[t]])){
				z=p-a[i];
				t=i;
			} 
		}
		ans++;
		for(long long i=t-1; i>=1; i--){
			if(m>=a[t]-a[i]){
				m-=(a[t]-a[i]);
				ans++;
			}
		}
		if(m>=0){
			for(long long i=t+1; i<=n; i++){
				if(m>=(a[i]-a[i-1])*(i-1)){
					m-=(a[i]-a[i-1])*(i-1);
					ans++;
		    	}
				else break;
			}
		}
		cout<<ans;		
	}
return 0;
}
