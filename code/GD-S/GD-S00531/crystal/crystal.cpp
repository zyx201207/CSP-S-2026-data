#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],s[500005],ch[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	bool flag=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		if(a[i]==a[i-1]){
			if(flag==1){
				cnt++;
			}else{
				flag=1;
				cnt=2;
			}
		}else{
			ans=max(ans,cnt);
			flag=0;
			cnt=0;
		}
	}
	if(a[n]==a[n-1]){
		ans=max(ans,cnt);
		flag=0;
		cnt=0;
	}
	ch[1]=a[1];
	for(int i=2;i<=n;i++){
		ch[i]=i*a[i]-s[i];
		if(ch[i]>m){
			ans=max(i-1,ans);
			break;
		}
	}
	if(ch[n]<=m&&ch[n]>0)ans=n;
	cout<<ans;
	return 0;
}
