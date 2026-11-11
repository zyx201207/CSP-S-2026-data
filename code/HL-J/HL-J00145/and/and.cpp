#include<bits/stdc++.h>
using namespace std;
string s,ss,sss;
int n,m;
long long a[200010],maxx;
string two(long long r){
	s="";
	ss="";
	long long cnt=0;
	while(r){
		s+=r%2+'0';
		r/=2;
		cnt++;
	}
	for(int i=0;i<30-cnt;i++){
		s+='0';
	}
	for(int i=0;i<30;i++){
		ss+=s[29-i];
	}
	return ss;
}
long long ten(string sp){
	long long ans=0,j=0;
	for(int i=sp.size()-1;i>=0;i--){
		ans+=(sp[i]-'0')*round(pow(2,j));
		j++;
	}
	return ans;
}
long long aand(long long p,long long q){
	sss="";
	string sa=two(p),sb=two(q);
	int l=max(sa.size(),sb.size());
	for(int i=0;i<l;i++){
		if(sa[i]=='1'&&sb[i]=='1') sss+='1';
		else sss+='0';
	}
	return ten(sss);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			maxx=max(aand(a[i],a[j]),maxx);
		}
	}
	cout<<maxx;
	return 0;
}
/*
4 2
3 15 12 12
*/