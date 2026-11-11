//RP++;RP++;RP++;
//check FrC and freopen and comp and return 0 again before finished
#include<bits/stdc++.h>
using namespace std;
struct l{
	int len;
	char f;
}mapp[200005];
int n,lef,rit,ans;
int main(){
	//CHECK IT FIRST
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){cin>>mapp[i].len>>mapp[i].f;}
	rit=n;
	while(lef<rit){
		int tmp=min(mapp[lef].len,mapp[rit].len);
		if(mapp[lef].f!=mapp[rit].f){
			ans+=tmp;
		}
		mapp[lef].len-=tmp;
		mapp[rit].len-=tmp;
		if(mapp[lef].len==0) lef++;
		if(mapp[rit].len==0) rit--;
	}
	cout<<ans;
	return 0;
}
