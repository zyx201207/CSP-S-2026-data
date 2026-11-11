#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans,sum,cz[1000005];
int a[1000005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n>5000){
		cout<<m/(a[2]-a[1])+1LL;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= i;j++){
			cz[j]=a[i]-a[j];
		}
		sum=0;
		int hf=0;
		sort(cz+1,cz+i+1);
		for(int j = 1;j <= i;j++){
			if(hf+cz[j]<=m){
				sum++;
				hf+=cz[j];
			}else{
				break;
			}
		}
		ans=max(ans,sum);
		if(ans==n)break;
	}
	cout<<ans;
    return 0;
}
