#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500020];
int ans[20000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n<=5000){
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		int w=1;
		for(int i=n;i>=1;i--){
			int h=a[i],s=m,ans1=0;
			for(int j=i-1;j>=1;j--){
				if(s-(h-a[j])>=0){
					s-=(h-a[j]);
					ans1+=1;
				}
				else{
					break;
				}
			}
			ans[w]=ans1;
			w++;
		}
		sort(ans+1,ans+n+1);
		cout<<ans[w-1]+1;
		return 0;
	}
	else if(n>5000){
		for(int i=1;i<=n;i++)cin>>a[i];
		int u=a[2]-a[1];
		int w=a[2]-a[1];
		int ans2=1;
		while(m-u>=0){
			m-=u;
			u+=w;
			ans2++;
		}
		if(ans2>=n){
			cout<<n;
			return 0;
		}
		else{
			cout<<ans2;
			return 0;
		}
	}
	return 0;
}
