#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct sec{
	ll len;
	char c;
};
vector<sec> str;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	ll sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		sum+=a;
		if(!str.empty()){
			if(c==str[str.size()-1].c)
				str[str.size()-1].len+=a;
			else str.push_back({a,c});
		}else str.push_back({a,c});
	}
	n=str.size();
	ll ans=0;
	ll h=1,t=sum;
	int hs=0,ts=n-1;
	ll hp=1,tp=str[n-1].len;
	while(h<t&&hs!=ts){
		ll flen=min(str[hs].len-hp+1,tp);
		if(str[hs].c!=str[ts].c)
			ans+=flen;
		h+=flen;
		t-=flen;
		hp+=flen;
		tp-=flen;
		if(hp>str[hs].len){
			hp=1,hs++;
		}
		if(tp<1){
			ts--;
			tp=str[ts].len;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
