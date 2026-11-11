#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long n,a[N],ans,m;
int iii(int n){
	while(n){
		if(n%2==0){
			n/=2;
		}else{
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ans=a[n];
	int cnt=1; 
	for(int i=n-1;i>=1;i--){
		if(iii(max(ans,a[i])/min(ans,a[i]))){
			//i--;
		}else{
			ans=ans&a[i];
			cnt++;
		}
		if(cnt==m){
			break;
		}
	}
	cout<<ans;
	return 0;
}
