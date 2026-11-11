#include<bits/stdc++.h>
using namespace std;
long long n,a,b[100001],ans;
bool cmp(long long x,long long y){
	return x>y;
}
long long toew(long long x,long long y){
	string p="",q="",v="";long long o=0;
	while(x!=0){
		p+=(x%2+'0');
		x/=2;
	}
	reverse(p.begin(),p.end());
	while(y!=0){
		q+=(y%2+'0');
		y/=2;
	}
	reverse(q.begin(),q.end());
	for(int i=0;i<p.size();i++){
		if(p[i]=='1'&&q[i]=='1') 
		v+="1";
		else v+="0";
	}
	reverse(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		o+=pow(2,i)*(v[i]-'0');
	}
	return o;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>n>>a;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	sort(b+1,b+n+1,cmp);
	for(int i=2;i<=a;i++){
		if(i==2)
			ans=toew(b[i],b[i-1]);
		else ans=toew(min(ans,b[i]),max(ans,b[i]));
	}
	cout<<ans;
	return 0;
}
