#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxn=0,yy;
long long y(long long a,long long b){
	if(a<b)swap(a,b);
	string a2,b2;
	long long c=0;
	while(a){
		a2=a2+char(a%2+'0');
		a/=2;
	}
	while(b){
		b2=b2+char(b%2+'0');
		b/=2;
	}
	for(int i=0;i<b2.size();i++){
		if(a2[i]==b2[i])a2[i]='1';
		else a2[i]='0';
	}
	if(a2.size()>b2.size()){
		for(int i=b2.size();i<a2.size();i++){
			if(a2[i]=='0')a2[i]='1';
			else a2[i]='0';
		}
	}
	for(int i=0;i<a2.size();i++){
		c=c+int(pow(2,i))*int(a2[i]-'0');
	}
	return c;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1)cout<<maxn;
	else{
		for(int i=1;i<=n;i++){
			if(i==1)yy=a[i];
			else yy=y(yy,a[i]);
		}
		cout<<yy;
	}
	return 0;
}
