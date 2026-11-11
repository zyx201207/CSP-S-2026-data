#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],ans,mx;
void d(int x,int s,int c){
	if(c==m){
		ans=max(ans,s);
		return;
	}
	if(x>n)return;
	d(x+1,s,c),d(x+1,s?s&a[x]:a[x],c+1);
}
signed main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],mx=max(mx,a[i]);
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)ans=(ans&a[i]);
		cout<<ans;
		return 0;
	}if(m==1){
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}if(mx<4){
		sort(a+1,a+1+n);
		int s=0,ans2=3,j=n,ss;ans=3;
		if(a[n]==3)for(int i=n;i>=1&&s<m&&a[i]==3;i--)s++,j=i;
		if(s==m){
			cout<<ans;
			return 0;
		}for(;j>=1&&a[j]==3;j--);
		ss=s;
		for(int i=1;i<=n&&s<m;i++)ans=(ans&a[i]),s++;
		s=ss;
		for(int i=j;i>=1&&s<m;i--)ans2=(ans2&a[i]),s++;
		cout<<max(ans,ans2);
		return 0;
	}if(n<=20){
		d(1,0,0);
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	cout<<a[n-m+1];
	return 0;
}
