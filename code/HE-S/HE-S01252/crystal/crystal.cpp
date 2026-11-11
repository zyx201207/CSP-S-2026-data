#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct t{
	ll num;
	ll many;
};
bool cmp(t a,t b){ 
	if(a.many!=b.many&&a.num>b.num){
		return a.many>b.many;
	}
	else{
		return a.num>b.num;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,m;
	cin>>n>>m;
	vector<ll> a(n);
	vector<ll> use(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++){
		use[i]=a[i];
	}
	unique(use.begin(),use.end());
	ll len=use.size();
	vector<t> b(len);
	for(ll i=0;i<len;i++){
		b[i].num=use[i];
	}
	b[0].many=0;
	ll c=0;
	for(int i=0;i<n;i++){
		if(b[c].num==a[i]){
			b[c].many++;
		}
		else{
			c++;
			b[c].many=1;
		}
	}//ÅÅÐò+ºÏ²¢ 
	sort(b.begin(),b.end(),cmp);
	ll cnt=1,cntm=m;
	/*for(ll i=1;i<len;i++){
		if(cntm-b[i].many>=0){
			count++;
			cntm-=b[i].many;
		}
		else{
			count++;
			break;
		}
	}*/
	ll ans=b[0].many;
	while(true){
		if(b[cnt].many*(b[0].num-b[cnt].num)>=m){
			ans+=b[cnt].many*(b[0].num-b[cnt].num)-m;
			break;
		}
		cnt++;	
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
