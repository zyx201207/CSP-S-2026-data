#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,a[N];
char c[N];
ll L,sum,ans,t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		L+=a[i];
	}
	int l=1,r=n;
	while (sum<=L/2 && l<=r){
		if (c[l]!=c[r]){
			if (a[l]==a[r]){
				sum+=a[l];
				ans+=a[l];
				l++; r--;
			}
			else if (a[l]>a[r]){
				sum+=a[r];
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
			else{
				sum+=a[l];
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
		else{
			if (a[l]==a[r]){
				sum+=a[l];
				l++; r--;
			}
			else if (a[l]>a[r]){
				sum+=a[r];
				a[l]-=a[r];
				r--;
			}
			else{
				sum+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
