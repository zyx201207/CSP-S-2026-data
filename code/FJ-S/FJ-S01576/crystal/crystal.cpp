#include<bits/stdc++.h>
using namespace std;

const long long N=5e5+5;
long long a[N],diff[N],ffid[N];
int ans=0;
long long n,m;
void ask(int l){
	long long sum=0;
	int nowans=1;
	while(sum <= m && nowans+l-1 < n){
		nowans ++ ;
		sum += nowans * diff[nowans + l - 1];
		
	}
	ans = max(ans, nowans);
}

int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);

	cin>>n>>m;
	long long flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) flag=a[i];
		else if(flag != a[i]){
			flag = 1e18;
		} 
	}
	if(n<=5000){
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++) diff[i]=a[i]-a[i-1];
	
		for(int i=1;i<=n;i++) {
			ask(i);
		}
		cout<<ans;
	}else if(flag != 1e18+5){
		cout<<n;
	}else{
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++) diff[i]=a[i]-a[i-1];
		for(int i=n;i>=1;i--) ffid[i]=ffid[i+1]+diff[i];
		int l=1,r=1;
		long long sum=0;
		long long nowans=1;
		while(l<=r && r<=n){
			
			/*while(sum <= m && nowans+l-1 < n){
				nowans ++ ;
				sum += nowans * diff[nowans + l - 1];
			}*/
			int len= r-l+1;
			if(sum<=m){
				r++;
				sum+= len*diff[r];
				//cout<<l<<" "<<r<<endl;
			}else{
				ans = max (ans, len-1);
				l++;
				sum-= (a[r]-a[l-1]);
				//cout<<l<<" "<<r<<endl;
			}
			
			
		}
		cout<<ans;
	} 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
