#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500500],cha=0,num=0,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	cha=abs(a[2]-a[1]);
	m/=cha;
	while (m>num){
		num+=1;
		m-=num;
		ans+=1;
	}
	cout<<ans;
	return 0;
}
