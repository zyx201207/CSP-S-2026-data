#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+5;
int a[N];
char c[N];
int sum[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum[i] = sum[i-1]+a[i];
	}
	int len = sum[n];
	int ans = 0;
	for(int i = 1;i<=n/2;i++){
		for(int j = sum[i-1]+1;j<=sum[i];j++){
			int xb = len-j+1;
			int w;
			for(int k = n/2;k<=n;k++){
				if(sum[k]>=xb){
					w = k;
					break;
				}
			}
			if(c[i]!=c[w])ans++;
		} 
	}
	cout<<ans<<"\n";
	
	return 0;
}
