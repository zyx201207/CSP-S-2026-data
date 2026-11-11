//GZ-S00222 谭斯雨 贵阳市第一中学 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n,ans;
ll m,a[N];
bool op=1;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1||i==2){
			continue;
		}
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			op=0;
		}
	}
	if(op==1){
		int ln=a[2]-a[1];
		for(int i=1;i<=n;i++){
			if(m-i*ln>=0){
				ans++;
				m-=i*ln;
			}
			else{
				break;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	sort(a+1,a+1+n,cmp);

	for(int j=n;j>=1;j--){
		if(j<=ans){
			break;
		}
		ll aka=m;
		int gr=1;
		for(int i=1;i<=n;i++){
			if(aka-a[j]+a[j-i]>=0){
				gr++;
				aka=aka-a[j]+a[j-i];
			}
			else{
				break;
			}
		}
		ans=max(ans,gr);
	}
	cout<<ans<<endl;
	return 0;
}
