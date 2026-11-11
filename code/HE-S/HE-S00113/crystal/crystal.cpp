#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5+100;
ll n,m,sum,ans,len = 0;
ll a[N];
ll b[N];
bool flag1=1,flag2=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			flag1 = 0;
		}
		if(i>2){
			if((a[i] - a[i-1])!=(a[i-1] - a[i-2])){
				flag2 = 0;
			}
		}
	}
	if(flag1||flag2){
		for(ll i=1;i<=n;i++){
			if(((i*(i+1))/2)*(a[2]-a[1]) <= m){
				ans = i;
			}
			else{
				cout<<ans + 1;
				return 0;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			sum = 0;
			len = 0;
			for(int j=i;j>=1;j--){
				if(sum + a[i] - a[j] <= m){
					sum += (a[i] - a[j]);
					len += 1;
				}
				else{
					break;
				}
			}
			ans = max(len,ans);
		}
		cout<<ans;
		return 0;
	}
}
