/*
QAQ
gei ge guan zhu miao~
id:ABANDON_AC
It's my last OI-test I'm AFO.
chafen ept:50pts
zai jian OI
goodbye

CSP-S:
#include<windows.h>
using namespace std;
int main(){
	Sleep(7200000);       //zzz
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500030],n,m;
ll cf[500030];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		cf[i]=a[i]-a[i-1];
	ll num=0;
	for(int i=2;i<=n;i++){
		int k;
		for(int j=i-1;j>=1;j--)
			if(cf[j]!=0){
				k=j;
				break;
			}
		num+=cf[i]*k;
		if(num>m){
			cout<<num-m<<' ';
			cout<<k;
			return 0;
		}
	}
	cout<<n;
	return 0;
}
