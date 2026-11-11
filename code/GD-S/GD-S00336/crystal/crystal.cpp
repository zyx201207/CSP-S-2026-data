#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=2e6+9;
const int inf=0x3f3f3f3f;
int n,m;
int a[N];
signed main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=-1;
	for(int f=1;f<=n;f++){
		int cnt=1,m2=m,now=0;
		for(int	i=f;i<=n;i++){
			if(a[i+1]==now) cnt++;
			if(a[i+1]>a[i]&&(a[i+1]-a[i])*(i-f+1)<=m2){
				now=a[i+1];
				cnt++;
				m2-=(a[i+1]-a[i])*(i-f+1);               
			}
		}
		ans=max(cnt,ans); 
	}
	cout<<ans<<endl;
	return 0;
}
