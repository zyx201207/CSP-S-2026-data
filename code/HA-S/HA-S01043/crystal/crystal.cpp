#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;
	cin>>n>>m;
	bool l=0,r=0;
	long long v=0;
	vector<long long> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=i+1){
			l=1;
		}
	}
	if(n==1){
		cout<<1<<"\n";
	}
	sort(a.begin(),a.end());
	
	v=a[1]-a[0];
	for(int i=1;i<n;i++){
		if(a[i]-a[i-1]!=v){
			r=1;
			break;
		}
	}
	if(r==0){
		for(int i=0;i<n;i++){
			if(m>=((v*i)+v)){
				m-=((v*i)+v);
				ans++;
			}
			
		}
		cout<<ans+1<<"\n";
	}else if(l==0){
		cout<<min((long long)sqrt((m*2)-(long long)sqrt(m*2))+1,n)<<"\n";
	}else{
		long long x=m,y=0;
		for(int i=1;i<n;i++){
			x=m,y=1;
			for(int j=i-1;j>=0;j--){
				long long t=a[i]-a[j];
				if(x>=t){
					y++;
					x-=t;
				}else{
					break;
				}
			}
			ans=max(ans,y);
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
}
