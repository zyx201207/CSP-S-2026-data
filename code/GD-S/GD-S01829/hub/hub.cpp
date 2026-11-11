#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int n,m,cot=0,cnt=0,kaka=0;
int a[N],asa=0;
bool f;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int C,T;cin>>C>>T;
	while(T--){
		cin>>n>>m;
		f=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>1&&i<n&&a[i+1]-a[i]!a[i]-a[i-1]){
				f=0;
			}
		}
		asa=a[2]-a[1];
		kaka=a[n]-a[1];
		if(kaka<=m){
			cout<<"0\n";
			continue; 
		}
		cnt=m/asa;
		if(cnt<=1){
			cout<<"0\n";
			continue;
		}
		cot=n+1-cnt*2;
		if(cot<=0){
			cout<<"0\n";
			continue;
		}
		cout<<cot<<"\n";
	}
	return 0;
} 
