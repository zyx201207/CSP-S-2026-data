#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[500005];
double cnt;

bool cmp(int b,int c){
	return abs(b*1.0-cnt)<abs(c*1.0-cnt);
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt+=a[i];
	}
	cnt/=n*1.0;
	sort(a+1,a+n+1,cmp);
	int fl=a[1];
	int ans=0;
	for(int i=1;i<=n;i++){
		int tmp=abs(a[i]-fl);
		if(m-tmp<0) continue;
		m-=tmp;
		a[i]=fl;
		ans++;
	}
	cout<<ans;
	return 0;
}
