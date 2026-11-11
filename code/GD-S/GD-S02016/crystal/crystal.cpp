#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
ll n,m,ans,ans2,x,x2,step,step2;
ll a[maxn],b[maxn];
ll solve1(){
	sort(a+1,a+n+1);
	ll mid=a[(n+1)/2];
	for(int i=1;i<=n;i++){
		if(a[i]==mid&&a[i-1]!=mid){
			x=i-1;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==mid) ans++;
		a[i]=mid-a[i];
	}
	for(;x>=1;x--){
		if(step+a[x]<=m){
			step=step+a[x];
			ans++;
		}else{
			break;
		}	
	}
	return ans;
}
ll solve2(){
	sort(b+1,b+n+1);
	ll mid2=b[(n+2)/2];
	for(int i=1;i<=n;i++){
		if(b[i]==mid2&&b[i-1]!=mid2){
			x2=i-1;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i]==mid2) ans2++;
		b[i]=mid2-b[i];
	}
	for(;x2>=1;x2--){
		if(step2+b[x]<=m){
			step2=step2+b[x];
			ans2++;
		}else{
			break;
		}	
	}	
	return ans2;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	if(n%2==1){
		cout<<solve1()<<'\n';
	}else{
		cout<<max(solve1(),solve2())<<'\n';
	}
} 
