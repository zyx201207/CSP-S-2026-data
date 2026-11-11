#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long m,n,a[N],t,f,x,s,sum,b[N],k,d,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int p=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=p){
			f=1;break;
		}
	}
	if(f==0){
		if(p==0) {
			if(n==m)cout<<n;
			else cout<<n-1;
		}
		else {
			for(int i=2;i<=n;i++)b[i]=b[i-1]+(i-1)*p;
			for(int i=1;i<=n;i++){
				if(b[i]<m)continue;
				else if(b[i]==m){
					x=i;
					break;
				}	
				else {
					x=i-1;
					break;
				}
			}
			int k=a[x];
			for(int i=1;i<=n;i++)b[i]=k-a[i];
			sort(b+1,b+n+1);
			for(int i=n-x+1;i<=n;i++){
				if(m>=b[i])s++,m-=b[i];
				else break;
			}
			cout<<s;
		}
	}
	else {
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1])k++;
			else d=max(d,k),k=0;
		} 
		if(n%2==0)t=n/2;
		else t=n/2+1;
		int v=a[t],ss=0,y=0;
		for(int i=1;i<=n;i++){
			if(v>=a[i])sum+=v-a[i];
		}
		for(int i=1;i<=n;i++)if(a[i]==v)ss++;
		for(int i=t+1;i<=n;i++)if(a[i]==v)ans++;
		if(sum==m){
			for(int i=1;i<=n;i++)b[i]=v-a[i];
			sort(b+1,b+n+1);
			for(int i=n-t+1;i<=n;i++){
				if(m>=b[i])s++,m-=b[i];
				else break;
			}
			cout<<s+ss-1;
			return 0;
		}
		for(int i=t+ans-1;i<=n;i++){
			sum+=(a[i]-v)*(i-1);
			if(sum>m){
				sum-=(a[i]-v)*(i-1);
				y=i-1;
			}
		}
		for(int i=1;i<=n;i++)b[i]=a[y]-a[i];
		sort(b+1,b+n+1);
		for(int i=n-y+1;i<=n;i++){
			if(m>=b[i])s++,m-=b[i];
			else break;
		}
		if(d>s)cout<<d+1;
		else cout<<s;
	}
	return 0;
}
