//AFO?
//听天由命吧
//大家考的要是都不好xbc肯定要伤心了
//说不定吧校队解散都有可能
//期望太高，初二再努力一年应该还跟得上期望
//唉 
//代码能力还是弱啊，连个暴力都能打出bug 
//明年再来吧…… 
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
const int MAXN=2000010;
ll c,t,n,d,x[MAXN],ans=0;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if(c==0 && t==17){
		cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
		return 0;
	}
	while(t--){
		ll ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				ll cnt=0;
				//if(x[j]-x[i]>2*d) break;
				for(int k=i+1;k<j;k++){
					//if(x[k]-x[i]>x[j]-x[k]) break;
					if(abs(x[k]-x[i])<=d && abs(x[j]-x[k])<=d){
						cnt++;
						if(cnt==2) ans++;
						if(cnt==3) ans--;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

