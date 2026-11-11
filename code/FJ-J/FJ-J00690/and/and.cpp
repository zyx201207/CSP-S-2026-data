#include<bits/stdc++.h>
using namespace std;
long long n,m,crr[200010];
long long yhh(long long a,long long b){
	long long arr[1010],brr[1010],ans=0,sen=0,c=1,sum;
	for(int i=1 ; i<=1010 ; i++){
		arr[i]=0;
		brr[i]=0;
	}
	while(a!=0){
		ans++;
		arr[ans]=a%2;
		a/=2;
	}
	while(b!=0){
		sen++;
		brr[sen]=b%2;
		b/=2;
	}
	for(int i=max(ans,sen) ; i>=1 ; i--){
		if(brr[i]!=0&&arr[i]!=0){
			sum+=2*c;
		}
		c*=2;
	}
	return sum;
}
int main(){
	long long ans=0;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1 ; i<=n ; i++){
		cin>>crr[i];
	}
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=n ; j++){
			if(i!=j){
				ans=max(ans,yhh(crr[i],crr[j]));
			}
		}
	}
	cout<<ans;
	return 0;
}
