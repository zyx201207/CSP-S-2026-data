#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int N=2e5+10;
int a[N];
char c[N];

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdin);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int ans=0;
	int i=1,j=n;
	while(i<j){
		if(c[i]!=c[j]){
			ans+=min(a[i],a[j]);
		}
		if(a[i]>=a[j]){
			a[i]-=a[j];
			j--;
		}else{
			a[j]-=a[i];
			i++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
