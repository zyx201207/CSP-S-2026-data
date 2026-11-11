#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long a[N],ans; 
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
		if(m==1&&n<=5){
			if(a[1]+m==a[2]){
				ans+=2;
				//continue;
			}
			else if(a[2]+m==a[3]){
				 ans+=2;//continue;
			}
			else if(a[3]+m==a[4]){
				 ans+=2;//continue;
			}
			else if(a[4]+m==a[5]){
				 ans+=2;//continue;
			}
	}
	
		if(m==2&&n<=5){
			if(a[1]+m==a[2]||a[1]+(m-1)==a[2]){
				ans+=2;
				//continue;
			}
			else if(a[2]+m==a[3]||a[2]+(m-1)==a[3]){
				 ans+=2;//continue;
			}
			else if(a[3]+m==a[4]||a[3]+(m-1)==a[4]){
				 ans+=2;//continue;
			}
			else if(a[4]+m==a[5]||a[4]+(m-1)==a[5]){
				 ans+=2;//continue;
			}
	}
	cout<<ans;
	
	return 0;
} 
