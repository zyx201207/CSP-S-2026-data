#include<bits/stdc++.h>
#define ll long long
#define N 200001
using namespace std;
ll n,m,a[N],ans,cnt,b[N],num;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=30;i>=0;i--){
		for(int j=1;j<=n;j++)
		if(a[j]&(1<<i)) b[++num]=a[j];
		if(num>=m){
			ans+=1<<i;
			for(int j=1;j<=num;j++) a[j]=b[j];
			n=num;
		}
		num=0;
	}
	cout<<ans<<endl;
	return 0;
}
