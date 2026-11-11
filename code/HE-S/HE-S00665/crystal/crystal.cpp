#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,m,a[N],cnt=1,q=1,p=1,ans=0,b[N],j=1,ma=INT_MIN;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i-1]=a[i]-a[i-1];
		if(a[i]!=a[i-1]){
			q=0;
		}
		if(i<=n-1){
			if(a[i]-a[i-1]!=a[i+1]-a[i]){
				p=0;
			}
		}
	}
	if(q==1){
		cout<<n;
		return 0;
	}
	if(p==1){
		ans=m/(a[2]-a[1]);
		while(ans>=0){
			if(ans-j<0){
				break;
			}
			ans-=j;
			j++;
			cnt++;
			if(cnt>=n){
				cnt=n;
			}
		}
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<n;i++){
		ans=0;
		for(int j=i;j<n;j++){
			if(ans+=b[j]*j>m){
				ma=max(ma,cnt);
				break;
			}
			ans+=b[j]*j;
			cnt++;
		}
	}
	cout<<ma;
	return 0;
}
