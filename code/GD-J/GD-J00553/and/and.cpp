#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[200005];
string s[200005];
string edge;
ll sum=0;
string found(int x){
	string m="";
	while(x!=0){
		if(x%2==0){
			m+='0';
		}
		else{
			m+='1';
		}
		x/=2;
	}
	return m;
}
string chose(string a,string b){
	string c="";
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for(int i=min(a.size(),b.size())-1;i>=0;i--){
		if(a[i]=='1'&&b[i]=='1'){
			c+='1';
		}
		else{
			c+='0';
		}
	}
	return c;
}
ll cmp(string s){
	ll cnt=0;
	int j=1;
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]=='1'){
			cnt+=j;
		}
		j*=2;
	}
	return cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=found(a[i]);
		reverse(s[i].begin(),s[i].end());
	}
	sort(s+1,s+n+1);
	for(int i=n;i>=m;i--){
		edge=s[i];
		for(int j=i-1;j>=i-m+1;j--){
			edge=chose(edge,s[j]);
		}
		sum=max(sum,cmp(edge));
	}
	cout<<sum;
	return 0;
} 
