/*
QAQ 
gei ge guan zhu miao~
id:ABANDON_AC
bu zhi dao ru he you hua
yong shi 1h
zhi jie pin ept:48pts
*/
#include<bits/stdc++.h>
#define AFO return 0;
using namespace std;
typedef unsigned long long ll;
int t;
int a[200010];
char c[200010];
char pin[100010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll num=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a[i]>>c[i];
		num+=a[i];
	}
	ll k=0;
	for(int i=1;i<=t;i++)
		for(int j=1;j<=a[i];j++)
			pin[++k]=c[i];
	ll ans1=0,ans2=0;
	for(ll i=1;i<=num/2;i++){
		if(pin[i]!=pin[i+num-1])
			ans1++;
	}
	for(ll i=num;i>=num/2;i--){
		if(pin[i]!=pin[num-i+1])
			ans2++;
	}
	cout<<((ans1<ans2)?(ans1):(ans2));
	AFO
}
