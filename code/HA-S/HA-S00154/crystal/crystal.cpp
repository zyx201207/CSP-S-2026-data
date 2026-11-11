#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010],cha[500010];
bool check(int x){
	int ans=0;
	for(int i=1;i<=n-x+1;i++){
		ans=0;
		for(int j=i;j<=i+x-1;j++){
			ans+=(a[j]-a[j-1])*(j-1);
			if(ans>m){
				break;
			}
		}
		if(ans<=m){
			return 1;
		}
	}
	return 0;
}
#undef int 
int main(){
	#define int long long
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[0]=a[1];
	bool flag=true;
	for(int i=2;i<=n;i++){
		cha[i]=a[i]-a[i-1];
		if(i!=2&&cha[i]!=cha[i-1]){
			flag=false;
		}
	}
	if(flag){
		cout<<m/cha[n];
		return 0;
	}
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
