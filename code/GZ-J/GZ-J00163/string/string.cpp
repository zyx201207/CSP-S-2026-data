//GZ-J00163  遵义市汇川区第二小学 韩铭钊 
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],ans;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int j=n,sheng=0,i;
	char shengc='@';
	for(i=1;i<=n && j>=i;i++){
		if(sheng){
			if(sheng>a[i]){
				if(shengc!=c[i]){
					ans+=a[i];
				}
				sheng-=a[i];
				continue;
			}
			if(shengc!=c[i]){
				ans+=sheng;
			}
			a[i]-=sheng;
		}
		int sum=0;
		while(sum+a[j]<=a[i]){
			sum+=a[j];
			if(c[j]!=c[i]){
				ans+=a[j];
			}
			j--;
		}
		if(c[j]!=c[i]){
			ans+=a[i]-sum;
		}
		sheng=a[j]+sum-a[i];
		shengc=c[j];
		j--;
	}
	if(sheng && shengc!=c[i]){
		ans+=sheng;
	}
	cout<<ans;
    return 0;
}
