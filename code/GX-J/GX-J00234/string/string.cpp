#include<bits/stdc++.h>
using namespace std;

int n,a[200005];
char c[200005];
long long z,ad[200005];
long long ans=0;

int wei(long long x){
	for(int i=1;i<=n;i++){
		if(x>ad[i-1]&&x<=ad[i])return i;
	}
}		


int main(){
    freopen("string4.in","r",stdin);
    freopen("string797564.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		ad[i]+=ad[i-1]+a[i];
		}
	z=ad[n]/2;
	
	
	for(int i=1;i<=wei(z);i++){
		int x=wei(ad[n]-ad[i]+1),y=wei(ad[n]-ad[i-1]);
		for(int j=y;j>=x;j--){
			
			if(a[i]>=a[j]&&c[i]!=c[j]){
				ans+=a[j];
				a[i]-=a[j];
				a[j]=0;
				}
			if(a[i]<a[j]&&c[i]!=c[j]){
				ans+=a[i];
				a[j]-=a[i];
				a[i]=0;
				}	
			
			}
		}
		
		cout<<ans;
		
		
		
		
	
	return 0;
}

