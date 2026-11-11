#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt=0,r,ans=0,s[500005],v[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		cnt+=s[i];	
		v[i]=s[i]-s[i-1];	
	}
	bool f=true;
	for(int i=2;i<n;i++){
		if(v[i]!=v[i+1]){
			f=false;
			break;
		} 
	}
	if(f==true){
		if(v[2]>m){
			cout<<1;
			return 0;
		} 
		else{
			r=(n+1)/2;
			cnt=s[r];
			for(int i=1;i<=r;i++){
				if(m-abs(cnt-s[i])>=0){
					m-=abs(cnt-s[i]);
					ans++;
				} 
				else break;
			}
			cout<<ans+1;
			return 0;
		}
	}
	sort(s+1,s+1+n); 	
	cnt/=n;
	for(int i=n;i>=1;i--){
		if(s[i]<cnt){
			if(abs(s[i]-cnt)<abs(s[i+1]-cnt)){
				r=i;
				break;
			} 
			else{
				r=i+1;
				break;
			} 			
		}
	}
	for(int i=r;i<n;i++){
		if(s[i]==s[i+1]) r=i+1;
	} 
	for(int i=1;i<=r;i++){
		if(m-abs(cnt-s[i])>=0){
			m-=abs(cnt-s[i]);
			ans++;
		} 
		else break;
	}
	cout<<ans;
	return 0;
}
