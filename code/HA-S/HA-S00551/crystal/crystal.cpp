#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],n,m;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int maxx=0;
	for(int i=1;i<=n;i++){
		int ned=m,cnt=1;
		for(int j=i+1;j<=n;j++){
			if(ned>=a[i]-a[j]){
				ned-=(a[i]-a[j]);
				cnt++;
			}else break;
		}
		maxx=max(maxx,cnt);
	}
	cout<<maxx;
	return 0;
}
