#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,ans;
long long m,a[N],b[N];
bool p=false;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			p=true;
			break;
		}
	}
	if(!p){
		int i=0,j=0;
		while(m>=0){
			i+=a[2]-a[1];
			m-=i;
			j++;
			if(j>=n){
				cout<<n;
				return 0;
			}
		}
		cout<<j;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long t=m;
		int sum=1,cnt=0;
		for(int j=i;j>=1;j--){
			if(i==j){
				continue;
			}
			b[++cnt]=a[i]-a[j];
		}
		sort(b+1,b+cnt+1);
		for(int j=1;j<=cnt;j++){
			if(t>=b[j]){
				t-=b[j];
				sum++;
			}else{
				break;
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
