//贵阳市新世界学校 李宗运 GZ-S00181 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],n,m,ans,cnt;
bool f=1,ff=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)f=0;
		if(i>=3 && ((a[i]-a[i-1])!=(a[i-1]-a[i-2])))ff=0;
	}
	if(f==1){
		for(int i=1;i<=n;i++)
			if(i*(i+1)>m*2){
				cout<<i;
				return 0;
			}
		cout<<n;
		return 0;
	}
	else if(ff){
		long long d=a[2]-a[1];
		if(d>m){
			cout<<1;
			return 0;
		}
		for(int i=2;i<=n;i++){
			if((a[i]-a[1])*i>m*2){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int ll=n;ll>=2;ll--){
		cnt=1;
		long long t=a[ll],v=m;
		for(int r=ll-1;r>=1&&v>0;r--){
			v-=t-a[r];
			if(v<0){
				break;
			}
			else cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
