#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,a[50005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	//n=pow(10,5)*5,m=pow(10,17);
	bool flag1=1,flag2=1;
	int u;
	cin>>a[1]>>a[2];
	u=abs(a[2]-a[1]);
	for(int i=3;i<=n;i++){
		cin>>a[i];
		//a[i]=i;
		if(a[i]!=a[i-1]+1){
			flag1=0;
		}
		if(u!=abs(a[i]-a[i-1])){
			flag2=0;
		}
	}if(flag1){
		int cnt=0;
		for(int i=1;i<=0x3f3f3f;i++){
			m-=i;
			if(m<=0)break;
			cnt++;
		}
		cout<<cnt;
		return 0;
	}else if(flag2){
		int cnt=-1;
		for(int i=0;i<=0x3f3f3f;i+=u){
			m-=i;
			if(m<=0)break;
			cnt++;
		}
		cout<<cnt;
		return 0;
	}
	cout<<a[2];
	return 0;
}
