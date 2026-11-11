#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,m,a[N],ans=0;
void dp(int x){
	int sum=0;
	for(int i=1;i<=x;i++){
		sum+=a[i];
	}
	sum/=x;
	int sum1=0;
	for(int i=1;i<=x;i++){
		sum1+=abs(a[i]-sum);
	}
	if(sum1<=m){
		ans=x;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		dp(i);
	}
	cout<<ans;
	return 0;
} 
