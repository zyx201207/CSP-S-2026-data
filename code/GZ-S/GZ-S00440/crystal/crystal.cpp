//GZ-S00440 ∆—Ω‹∫¿ ◊Ò“Â“ª÷–
#include <bits/stdc++.h>
using namespace std;
long long a[500015],cf[500015],qz[500015],qjh[666];
long long n,m,ans=1,h;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	cf[i]=a[i]-a[i-1];
	for(int i=1;i<=n;i++)
	qz[i]=cf[i+1]+qz[i];
	while(h<=m){
	ans++;
	h+=ans*qz[ans];}
	cout<<ans;
	return 0;
}

