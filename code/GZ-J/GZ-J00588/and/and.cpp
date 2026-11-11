#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[25],ans,sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){for(int i=1;i<=n;i++)ans=max(ans,a[i]);cout<<ans;}
	else if(m==2){
		for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)ans=max(a[i]&a[j],ans);
		cout<<ans;
	}
	else if(m==n){ans=a[1];for(int i=2;i<=n;i++)ans&=a[i];cout<<ans;}
	else if(n<=20){
		for(int i=7;i<pow(2,n);i++){
			int j=i,cnt=0,p=0;
			while(j){if(j%2){cnt++;}p++;b[p]=j%2;j/=2;}
			if(cnt!=m)continue;
			sum=pow(2,21)-1;
			for(int k=1;k<=p;k++)if(b[k])sum&=a[k];
			ans=max(sum,ans);
		}
		cout<<ans;
	}
	else if(m==n-1){
		for(int i=1;i<=n;i++){
			if(i==1)sum=a[2];
			else sum=a[1];
			for(int j=2;j<=n;j++)if(i!=j)sum&=a[i];
			ans=max(sum,ans);
		}
		cout<<ans;
	}
	else{
		sort(a+1,a+1+n);
		ans=a[1];
		for(int i=2;i<=m;i++)ans&=a[i];
		cout<<ans;
	}
	return 0;
}
