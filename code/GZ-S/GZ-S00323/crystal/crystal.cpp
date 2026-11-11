//GZ-S00323 贵阳市第十九中学 唐靖越 
#include<bits/stdc++.h>
using namespace std;
long long n,m,s,ans=-1;
long long a[15000000]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1 ; i <=  n ;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(a[n+1]==a[1]){
		cout<<n;
		return 0;
	}
	for(int i = n ; i >=1;i--){
		int m1=m;
		s=0;
		for(int j = i-1 ; j >= 1;j--){
			if(m1<=0){
				break;
			}
			if(a[j]+m1>a[i]){
				s++;
				m1-=a[i]-a[j];
			}
			else if(a[j]+m1==a[i]){
				s++;
				break;
			}
			else{
				break;
			}
			
		}
		if(s+1==i){
			cout<<s+1;
			return 0;
		} 
		
		ans=max(s+1,ans);
	}
	cout<<ans;
	return 0 ;
} 

