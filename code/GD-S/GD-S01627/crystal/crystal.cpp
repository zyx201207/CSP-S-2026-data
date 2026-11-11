#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=500005;
int n,m,ans,p;
int a[MAXN],s[MAXN];
void subA(){
	int sum=0,k=0;
	for(int i=1;i<=n;i++){
		if(sum+i>m)
			break;
		sum+=i,k=i;
	}
	cout<<k+1;
}
void subB(int x){
	int sum=0,k=0;
	for(int i=1;i<=n;i++){
		if(sum+i*x>m)
			break;
		sum+=i*x,k++;
	}
	cout<<k+1;
} 
void init(){
	for(int i=1;i<=n;i++)
		a[i]=s[i];
}
int check(){
	int maxx=0,cnt=0,k=a[1];
	for(int i=1;i<=n;i++){
		if(a[i]==k)
			cnt++;
		else
			k=a[i],maxx=max(maxx,cnt),cnt=1;
	}
	maxx=max(maxx,cnt);
	return maxx;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i],s[i]=a[i];
		if(a[i]==i)
			p++;
	}
	if(p==n){
		subA();
		return 0;
	}
	p=0;
	int h=a[2]-a[1];
	for(int i=1;i<n;i++)
		if(a[i]+h==a[i+1])
			p++;
	if(p==n-1){
		subB(h);
		return 0;
	}
	sort(a+1,a+1+n);
	sort(s+1,s+1+n);
	for(int i=1;i<=n;i++){
		int sum=0;
		init();
		for(int j=i;j>=1;j--){
			if(sum+a[i]-a[j]>m)
				break;
			sum+=a[i]-a[j];
	 		a[j]=a[i]; 
		}
		ans=max(ans,check());
	}
	cout<<ans;
	return 0;
}
