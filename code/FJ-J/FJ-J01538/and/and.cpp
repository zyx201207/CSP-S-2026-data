#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,t[200010],pp=0;
string s[200010];
string zj(long long n){
	string q="";
	while(n){
		q=char(n%2+48)+q;
		n/=2;
	}
	return q;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&t[i]);
		s[i]=zj(t[i]);
		if(pp<t[i])pp=t[i];
	}

	string l=zj(pp);
	int o=l.size();
	for(int i=1;i<=n;i++){
		while(s[i].size()<o){
			s[i]='0'+s[i];
		}
	}
	long long r=pow(2,o-1);
	for(int j=0;j<o;j++){
		long long p=0;
		for(int i=1;i<=n;i++){
			if(t[i]>=ans && s[i][j]=='1')p++;
			if(p>=m)break;
		}
		if(p>=m){
			ans+=r;
		}
		r/=2;
	}
	cout<<ans;
	return 0;
}
