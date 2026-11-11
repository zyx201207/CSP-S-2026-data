//GZ-S00336 贵阳市第九中学 张宛钰 
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n;
long long m;
long long a[maxn],ca[maxn];
int ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		ca[i]=(abs(a[i]-a[i-1])*(i-1))+ca[i-1];
		if(ca[i]>m) {
			ans=i-1;
			break;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
