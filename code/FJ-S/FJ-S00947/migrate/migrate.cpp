#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=3000010;
int c,t,n,d;
int a[MAXN];
bool pan(int x,int y){
	bool qq,dd,jj,mm;
	if(qq==dd&&qq==jj&&qq==mm)  return true;
	else return false;
}
void solve(){
	scanf("%lld%lld",&n,&d);
	int s=0;
	for(int i=1;i<=n;i++)  scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(pan(i,j))  s++;
		}
	}
	printf("%lld\n",s);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
