#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200010],ss,sum,ans;
char c[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	sum/=2;
	int j=n;
	for(int i=1;i<=n;i++){
		if(ss>=sum) break;
		ss+=a[i];
		if(ss>sum){
			a[i]=sum-ss+a[i];
			ss=sum;
		}
		int sss=0;
		while(sss<=a[i]){
			sss+=a[j];
			if(sss<=a[i]&&c[j]!=c[i]){
				ans+=a[j];
			}
			if(sss>a[i]&&c[j]!=c[i]){
				ans+=a[i]-sss+a[j];
			}
			j--;
		}
		j++;
		a[j]=sss-a[i];
	}
	cout<<ans;
	return 0;
}
