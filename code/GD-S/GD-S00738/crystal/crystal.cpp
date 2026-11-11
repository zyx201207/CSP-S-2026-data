#include<bits/stdc++.h>
using namespace std;
namespace FZT{
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],sum;
int ans;
void Main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1,j=1;j<=n;j++){
		sum+=(a[j]-a[j-1])*(j-i);
		while(sum>m){
			sum-=(a[j]-a[i]);
			i++;
		}
		ans=max(ans,j-i+1);
	}
	cout<<ans;
}}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	FZT::Main();
	return 0;
}
