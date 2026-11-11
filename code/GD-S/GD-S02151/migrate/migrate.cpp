#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#define LL long long
using namespace std;
const int N=5e6+10;
const int Inf=0x3f3f3f3f;
LL c,t,n,d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
//	if(c==11||c==12)
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i]; 
			}if(x[1]+d>=x[2]&&x[1]+d>=x[3]&&x[2]+d>=x[4]){
				cout<<n-3<<'\n';
			}else cout<<0<<'\n';
		}
	return 0;
}

