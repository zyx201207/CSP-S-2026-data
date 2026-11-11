#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;
int a[200005];
string two(int x){
	string s="";
	while(x>1){
		if (x%2==0) s+='0';
		else s+='1';
		x/=2;
	}
	if (x==1) s+='1';
	else s+='0';
	int len=s.size();
	if (len<4){
		for (int i=1;i<=4-len;i++){
			s+='0';
		}
	}else{
		for (int i=1;i<=len%4;i++){
			s+='0';
		}
	}
	return s;
}
int kf(int x){
	int cnt=1;
	for (int i=1;i<=x;i++){
		cnt*=2;
	}
	return cnt;
}
int an(int x,int y){
	string x1=two(x),y1=two(y);
	string s="";
	int len1=x1.size(),len2=y1.size();
	for (int i=0;i<=max(len1-1,len2-1);i++){
		if (x1[i]==y1[i] && x1[i]=='1') s+='1';
		else s+='0';
	}
	int len=s.size();
	int cnt=0;
	for (int i=0;i<=len-1;i++){
		cnt+=(s[i]-'0')*kf(i);
	}
	return cnt;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=a[n];
	for (int i=n-1;i>n-m;i--){
		ans=an(ans,a[i]);
	}
	cout<<ans;
	return 0;
}
