#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=550000;
int n,m;
int a[maxn];
void TA(){
	sort(a+1,a+n+1);
	int cnt=0;
	for(int i=2;i<=n;i++){
		if(m>=(a[i]-a[i-1])*(i-1)){
			m-=(a[i]-a[i-1])*(i-1);
			cnt=i;
		}else{
			break;
		}
	}
	cout<<cnt;
}
signed main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin>>n>>m;
//	bool f=true;
	if(n==0){
		cout<<0<<endl;
		return 0; 
	}
	a[0]=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	TA();
	//cout<<f;
	return 0;
} 
