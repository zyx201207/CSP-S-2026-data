#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int n,a[maxn];
char c[maxn];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int len=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	int l=0,r=0,ans=0;
	//l ×ó¶ËÒÑÆ¥Åä
	//r ÓÒ¶ËÒÑÆ¥Åä 
	int cnt=0;
	//cnt Á½¶ËÆ¥ÅäÊı 
	for(int L=1,R=n;cnt<=len/2&&L<R;){
		int restL=a[L]-l,restR=a[R]-r;
		if(c[L]==c[R]){
			if(restL>=restR){
				l+=restR;
				R--,r=0;
			}
			else{
				r+=restL;
				L++,l=0;
			}
			//cout<<'\n';
			//cout<<"L-R  "<<L<<' '<<R<<'\n';
			//cout<<"l-r  "<<l<<' '<<r<<'\n';
			//cout<<"cnt - ans  "<<cnt<<" - "<<ans<<'\n';
			continue;
		}
		if(restL>=restR){
			cnt+=restR;
			l+=restR;
			restL-=restR;
			ans+=restR;
			restR=0,R--,r=0;
			if(restL<=0)L++,l=0;
		}
		else{ // restL < restR
			cnt+=restL;
			r+=restL;
			restR-=restL;
			ans+=restL;
			restL=0,L++,l=0;
			if(restR<=0)R--,r=0;
		}
		//cout<<'\n';
		//cout<<"L-R  "<<L<<' '<<R<<'\n';
		//cout<<"l-r  "<<l<<' '<<r<<'\n';
		//cout<<"cnt - ans  "<<cnt<<" - "<<ans<<'\n';
	}
	cout<<ans;
	return 0;
}
/*
7
2 a
2 b
3 a
2 c
1 d
2 b
1 a


aa bb aaa cc d bb a
*/
