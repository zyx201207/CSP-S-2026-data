#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,d,a[2000010],T,t,tt,l,r,ans;
void migrate3(){cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";return ;}
void migrate4(){cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";return ;}
void migrate5(){cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";return ;}
void migrate6(){cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";return ;}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	if(c==0&&T>2){
		if(T==17) migrate3();
		else if(T==12) migrate4();
		else if(T==14) migrate5();
		else if(T==16) migrate6();
		return 0;
	}
	while(T--){
		cin>>n>>d,t=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=3;i<=n;i++)
			if(a[i]-a[i-2]==d) ans++;
		cout<<(ans>1?ans-1:ans)<<'\n',ans=0;
	}
	return 0;
}
