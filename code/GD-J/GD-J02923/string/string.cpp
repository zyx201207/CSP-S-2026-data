#include<bits/stdc++.h>
#define int long long
using namespace std;
string s,t;
int n,a[1000001],sum,ans,cnt,p,qian,hou;
char c[1000001];
void fan(){
	sum=s.size();
	t=s;
	reverse(t.begin(),t.end());
	if(t==s) cout<<0,exit(0);
	int l=s.size();
	ans=sum/2;
	if(sum%2==1) p=1,cnt=ans+1;
	else p=0,cnt=ans;
	for(int i=0;i<sum;i++){
		if(t[i]!=s[i]){
			if(i<=ans) qian++;
			else hou++;
		}
	}
	cout<<min(qian,hou),exit(0);
}
main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	fan();
}
