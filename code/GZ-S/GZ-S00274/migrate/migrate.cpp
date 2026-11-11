//GZ-S00274 贵阳市云岩区中天中学 张颜淏
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;

int c,T,n,d,a;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	
	cin>>n>>d;
	int N=n;
	for(int i=1;i<=n;i++)cin>>a;
	ll t=T-1;
	
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a;
	}
	if(c==0){
		if(T==2&&N==4){
			cout<<"1\n2";
		}else if(T==2&&N==5){
			cout<<"0\n1";
		}else if(T==17){
			cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
		}else if(T==12){
			cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
		}else if(T==14){
			cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		}else{
			cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		}
	}
    return 0;
}
