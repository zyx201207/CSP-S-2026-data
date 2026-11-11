#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[500005],ans=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		ans++;
		if(m-(a[i+1]-a[i])*i<0){break;}
		else{m-=(a[i+1]-a[i])*i;cout<<m<<' '<<a[i]<<' '<<i<<'\n';}
		
	}
	cout<<ans;
	return 0;
}
/*
¹Ø×¢Hamster_EmperorÐ»Ð»ß÷ 
*/
