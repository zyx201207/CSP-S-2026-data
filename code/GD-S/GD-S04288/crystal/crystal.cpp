#include<bits/stdc++.h>
using namespace std;
const int N=500050;
int n;
long long m,a[N],b[N];
int ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int c=a[2]-a[1];
	bool flag=1;
	for(int i=3;i<=n;i++)
		if(c!=a[i]-a[i-1]){
			flag=0;
			break;
		}
	if(flag){
		for(int i=2;i<=n;i++){
			b[i]=a[i]-a[i-1]+b[i-1];
		}
		for(int i=2;i<=n;i++){
			if(m>=b[i]){
				m-=b[i];
				ans++;
			}
			else
				break;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int x=m,cnt=1;
		for(int j=i-1;j>=1;j--){
			if(x>=a[i]-a[j]){
				x-=(a[i]-a[j]);
				cnt++;
			}
			else{
				break;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
