#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int c[N];
int dc(){
	int cha=a[2]-a[1];
	for(int i=1;i<=n+1;i++){
		int ans=(cha+ cha+(i-2)*cha)*(i-1)/2;
		if(ans>m||i>n){
			return i-1;
		}
	}
}
int baoli(){
	for(int i=2;i<=n;i++){
		c[i-1]=a[i]-a[i-1];
	}
	int sum=0,cnt=1,mx=0;
	for(int s=1;s<=n;s++){
		for(int e=s;e<=n+1;e++){
			if(sum>m||e>n){
				mx=max(mx,e-s);
				break;
			}
			sum+=c[e]*cnt;
			cnt++;
		}
		cnt=1;
		sum=0;
	}
	return mx;
}
int zhiyu(){
	int sum=0,cnt=0,mx=0;
	for(int i=-100;i<=100;i++){
		sum=0,cnt=0;
		for(int j=n;j>=1;j--){
			if(sum>m){
				mx=max(mx,cnt-1);
				break;
			}
			if(a[j]<=i){
				sum+=i-a[j];
				cnt++;
			}
		}
	}
	return mx;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	int max_=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];    
		max_=max(max_,abs(a[i])); 
	}
	sort(a+1,a+1+n);
	if(n<=5000){
		cout<<baoli();
	}
	else if(max_<=100){
		cout<<zhiyu();
	}
	else{
		cout<<dc();
	}
	return 0;
}
