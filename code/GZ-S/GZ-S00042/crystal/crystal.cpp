//GZ-S00042 贵阳市观山湖区外国语实验中学 孙小涵 
#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int md=n/2;
	long long c=0;
	for(int i=md-1;i>0;i--){
		m-=(a[md]-a[i]);
		c++;
		if(m<0){
			m+=(a[md]-a[i]);
			c--;
			break;
		}
		else if(m==0){
			break;
		}
	}
	while(m>0){
		int ch=a[md+1]-a[md];
		if(m-c*ch>=0){
			c++;
			m-=c*ch;
			md++;
		}
		else break;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[md]) c++;
	}
	if(c>n) cout<<n;
	else cout<<c;
	return 0;
} 
