#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
unsigned long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	unsigned long long res=0;
	if(n<=20){
		sort(a+1,a+n+1,greater<int>());
		for(int i=1;i<=(1<<n)-1;i++){
			unsigned long long ans=-1,cnt=0;
			for(int j=0;j<n;j++){
				if(i&(1<<j)){
					cnt++;
					if(ans==-1) ans=a[j];
					else ans&=a[j];
				}
			}
	//		cout<<i<<' '<<ans<<'\n';
	 		if(cnt==m){
	// 			cout<<i<<' '<<ans<<'\n';
	 			res=max(ans,res); 
			}
		}
	}else if(m==1){
		for(int i=1;i<=n;i++) res=max(res,a[i]);
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++) res=max(res,a[i]&a[j]);
		}
	}
	cout<<res;
}
