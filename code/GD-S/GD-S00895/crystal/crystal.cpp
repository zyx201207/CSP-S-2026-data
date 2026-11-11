#include<bits/stdc++.h>
using namespace std;
long long n,m,num,ans,a[500010],b[500010],cnt,c;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
	cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++){
		if(i==2)
		cnt=a[2]-a[1];
		if(i>2&&a[i]-a[i-1]!=cnt)
		c=1;
		b[i]=a[i];
		b[i]+=b[i-1];
	}
	if(c==1||n<3){
	for(long long i=n; i>=1; i--){
		for(long long j=1; j<=i; j++){
			if(a[i]*(i-j+1)-b[i]+b[j-1]<=m){
			ans=max(ans,i-j+1);
			}
		}
	}
}
   else{
		while(a[1]*(num*(num+1)/2)<=m){
			num++;
		}
		ans=num;
	}
	cout<<ans;
	return 0;
} 
