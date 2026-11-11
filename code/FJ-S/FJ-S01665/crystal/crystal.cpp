#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f 
#define endl '\n'
int n,m;
int ans=0;
int a[50505];
int b[50305];
int c[50505];
void s(int x){
if(x==m){
int f=1;
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]+b[i];
	}
	sort(c+1,c+1+n);
	for(int i=1;i<=n;i++){
		if(c[i]==c[i+1])f++;
		else{
			ans=max(f,ans);
			f=1;
			
		}
	}
	return ;
}else{
for(int i=1;i<=n;i++){
	b[i]++;
	b[i+1]--;
	s(x+1);
	b[i]--;
	b[i+1]++;
}
}
}
signed main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>a[i];
sort(a+1,a+1+n);
for(int i=1;i<=n;i++){
	b[i]=a[i]-a[i-1];
}
s(0);
cout<<ans;


return 0;
}
