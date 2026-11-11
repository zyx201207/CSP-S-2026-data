#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct number{
	string s;
	int v;
}s[N];
int n,m,ans,a[N];
bool cmp(number x,number y){
	return x.s>y.s;
}
string change(int x){
	string s1,s2;
	int now=x;
	while(1){
		if(now==0){
			break;
		}
		if(now%2==0)s1+='0';
		else s1+='1';
		now=now/2;
	}
	for(int i=s1.size()-1;i>=0;i--)s2+=s1[i];
	return s2;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i].s=change(a[i]);
		s[i].v=a[i];
	}
	sort(s+1,s+1+n,cmp);
	ans=s[1].v;
	for(int i=2;i<=m;i++)ans=ans&s[i].v;
	cout<<ans;
	return 0;
}
