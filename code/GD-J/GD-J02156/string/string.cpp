#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,a[200005],sum=0,r=0;
char c[200005];
char find(int x){
	int tmp=0;
	for(int i=1;i<=n;i++){
		if(tmp+a[i]<x) tmp+=a[i];
		else return c[i];
	}
} 
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i],sum+=a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			if(find(sum-i+1)!=c[i]) ans++;
			r++;
			if(2*r>=sum){
				cout<<ans;
				return 0;
			}
		}
	}
	return 0;
}
