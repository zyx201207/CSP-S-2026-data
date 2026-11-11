#include<bits/stdc++.h>
using namespace std;
int a[100001];
string bs(int x){
	int ans=1;
	while(ans<=x)ans*=2;
	ans/=2;
	string s="";
	while(x>0){
		if(x>=ans){
			s+='1';
			x-=ans;
			ans/=2;
		}else{
			s+='0';
			ans/=2;
		}
	}
	string c="";
	for(int i=s.size();i>=0;i--)c+=s[i];
	return c;
}
int ds(string s,string t){
	string c="";
	if(s.size()<=t.size()){
		for(int i=0;i<s.size();i++){
			if(s[i]=='1' && t[i]=='1')c+='1';
			else c+='0';
		}
	}else{
		for(int i=0;i<t.size();i++){
			if(s[i]=='1' && t[i]=='1')c+='1';
			else c+='0';
		}
	}
	int cnt=0,a=1;
	for(int i=c.size()-1;i>=0;i--){
		if(c[i]=='1'){
			cnt+=a;
			a*=2;
		}else{
			a*=2;
		}
	}
	return cnt;
}
int main(){
	freopen(and.in);
	freopen(and.out);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int cnt=a[n-1];
	for(int i=n-2;i>n-m-1;i--){
		string x,y;
		x=bs(cnt);
		y=bs(a[i]);
		cnt=ds(x,y);
	}
	cout<<cnt;
	return 0;
}

