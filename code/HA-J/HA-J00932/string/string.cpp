#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
char fu[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i]>>fu[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	int l=1;
	int len=0;
	int shang=n;
	int ans=0;
	for(int j = n;j>=1;j--){
		
		if(j<l)break;
		if(len+a[j]<a[l]){
			len+=a[j];
			continue;
		}
		a[j]-=a[l]-len;
		for(int u=shang;u>=j+1;u--){
			if(fu[l]!=fu[u]){
				ans+=a[u];
			}
		}
		if(fu[l]!=fu[j])ans+=a[l]-len;
		l++;
		shang=j;
		len=0;
		j++;
		
	}
	cout<<ans;
	
	return 0;
} 
