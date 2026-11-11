#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
const int N=5e5+5;
long long a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ma=0;
	for(int i=1;i<=n;i++){
		int num=m;
		int ans=0;
		for(int j=i;j>=1;j--){
			if(num>=a[i]-a[j]){
				num-=(a[i]-a[j]);
				ans++;
			}
		}
		ma=max(ma,ans);
	}
	cout<<ma;
	return 0;
}
/*5 8
-3 -1 2 2 7*/
/*5 5
1 2 4 8 9*/
