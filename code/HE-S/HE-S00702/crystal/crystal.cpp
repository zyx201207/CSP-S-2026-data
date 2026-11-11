#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long ans=1;
long long n,m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	a[0]=a[1];
	long long lst=1,sum=0;
	for(int i=1;i<=n;i++){
		sum+=1ll*(i-lst)*(a[i]-a[i-1]);
		while(sum>m&&lst<i){
			sum-=a[i]-a[lst];
			lst++;
		}
		ans=max(ans,i-lst+1);
	}
	cout<<ans;
	return 0;
} 
