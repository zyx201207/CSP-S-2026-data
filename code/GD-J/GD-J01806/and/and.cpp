#include<bits/stdc++.h>
using namespace std;
long long a[220000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    long long n,m,ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=30;i>=0;i--){
		long long x=(1<<i),tmp=0;
		for(int j=0;j<n;j++){
			if((a[j]&x)&&(a[j]>>(i+1))>=ans){
				tmp++;
			}
		}
		if(tmp>=m){
			ans=(ans<<1)+1;
		}else{
			ans=(ans<<1);
		}
	}
	cout<<ans;
	return 0;
}
