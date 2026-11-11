#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
long long n,m,a[N],sum,ans;
long long f[N],sam[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(f[a[i]]){
			sam[f[a[i]]+1]=max(sam[f[a[i]+1]],a[i]);
		}
		f[a[i]]++;
	}
	sort(a+1,a+n+1);
	sum=a[n];
	ans=sum&sam[m-1];
	for(int i=2;i<=m;i++){
		sum&=a[n-i+1];
		ans=max(ans,sum&sam[m-i]);
	}
	ans=max(ans,sum);
	ans=max(ans,sam[m]);
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
}
