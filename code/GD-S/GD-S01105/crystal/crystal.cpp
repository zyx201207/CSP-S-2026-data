#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
const int N=5e5+10;
long long int n,m,a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	int t=0,gc;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	gc=a[2]-a[1];
	for(int i=2;i<=n;i++) {
		if(a[i]-a[i-1]!=gc){
			t=1;
			break;
		}
	}
	if(!t){
		long long int summ=0,ans=1;
		for(int i=1;i<=n;i++){
			summ+=i*gc;
			if(summ<=m){
				ans++;
			}
			else{
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	if(t){
		sum[1]=0;
		for(int i=2;i<=n;i++){
			sum[i]=sum[i-1]+abs((i-1)*(a[i]-a[i-1]));
		}
		long long int ans=0,maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(m>=(sum[j]-sum[i])&&maxx<=j-i+1){
					maxx=j-i+1;
					ans=j-i+1;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
