#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[5000005],ans,usi=1,zc,tyi=1;
char c[5000005];
bool f;
struct node{
	ll st,ed;
	char c;
	bool u;
	node(ll _st=0,ll _ed=0,char _c=0, bool _u=0){
		st=_st;
		ed=_ed;
		c=_c;
		u=_u;
	}
} us[5000005],ut[5000005],ty[5000005];
ll ql(node a){
	return a.ed-a.st+1;
}vector<char> ha;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%s",&a[i],&c[i]);
		us[i]=node(us[i-1].ed+1,us[i-1].ed+a[i],c[i],1);
		zc+=a[i];
		ty[i]=node(us[i-1].ed+1,us[i-1].ed+a[i],c[i],1);
		for(ll j=0;j<ql(us[i]);j++){
			ha.push_back(us[i].c);
		}
	}for(ll i=0;i<ceil(1.0*ha.size()/2);i++){
		if(ha[i]!=ha[ha.size()-i-1]) ans++;
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}




































