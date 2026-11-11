//华东师范大学附属贵阳学校 陈睿阳 GZ-S00286 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m;
long long a[N],cnt=1,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	for (int i=n;i>=1;i--){
		int t=m;
		for (int j=i-1;j>=1;j--){
			int c=a[j]-a[i];
			if (t+c>=0){
				t+=c;
				cnt++;
			}else break;
		}
		ans=max(ans,cnt);
		cnt=1;
	}
	cout << ans;
	return 0; 
}
