#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
ll n,a[maxn],tot,sum[maxn],ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		char c;
		cin>>c;
		for(int j=1;j<=a[i];j++){
			sum[++tot]=c-'a';
		}
	}
	for(int i=1;i<=tot/2;i++){
		ll tmp=tot-i+1;
		if(sum[i]!=sum[tmp]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
