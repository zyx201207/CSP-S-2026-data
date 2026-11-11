#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int cnt1,cnt2;
long long a[2000009];
long long b[2000009];
int qd,zd;
bool pd(int x,int y){
	if((a[y]-a[x])%d==0){
		return 0;
	}
	if(a[y]-a[x]<=d){
		return 0;
	}
	cnt1=0;
	cnt2=0;
	qd=a[x];
	for(int i=x;i<=y;i++){
		zd=a[i+1];
		if(i>x&&(a[i]-a[i-1])>d){
			return 0;
		}
		if(abs(zd-qd)>=d){
			cnt1++;
			qd=a[i];
		}
	}
	qd=a[y];
	for(int i=y;i>=x;i--){
		zd=a[i-1];
		if(abs(zd-qd)>=d){
			cnt2++;
			qd=a[i];
		}
	}
	if((x-y+1)%2!=0&&a[x]-a[x/2+1]<d&&a[x/2+1]-a[y]<d){
		return 0;
	}
	if(cnt1==cnt2){
		return 1;
	}
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
cin>>c>>t;
for(int i=1;i<=t;i++){
	int ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-2;i++){
		for(int j=n;j>=i+2;j--){
			if(pd(i,j)){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}	
	return 0;
}
