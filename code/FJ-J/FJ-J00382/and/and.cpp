#include<bits/stdc++.h>
using namespace std;
long long a[1000005],m,n,ans=0;

string jizhi(long long st){
	string s="";
	long long cnt=0;
	long long i=1;
	if (st==1){
		return "1";
	}
	if (st==0){
		return "0";
	}
	while (st>=i){
		i*=2;
		cnt++;
	}
	i/=2;
	cnt--;
	string q=jizhi(st-i);
	s="1"+s;
	for (int i=1;i<=cnt-q.length();i++){
		s=s+"0";
	}
	s=s+q;
	return s;
	
}
int zhi(long long q,long long p){
	long long ans=1;
	for (int i=1;i<=p;i++){
		ans*=q;
	}
	return ans;
}
long long check(long long q,long long p){
	string s1=jizhi(q);
	string s2=jizhi(p);
	string s="";
	long long sl1=s1.length(),sl2=s2.length();
	if (sl1>sl2){
		for (int i=1;i<=sl1-sl2;i++){
			s2="0"+s2;
		}
	}
	else if (sl1<sl2){
		for (int i=1;i<=sl2-sl1;i++){
			s1="0"+s1;
		}
	}
	for (int i=0;i<max(sl1,sl2);i++){
		if (s1[i]=='1' && s2[i]=='1'){
			s=s+"1";
		}
		else{
			s=s+"0";
		}
	}
	long long ans=0;
	for (int i=0;i<max(sl1,sl2);i++){
		if (s[i]=='1'){
			ans+=zhi(2,max(sl1,sl2)-i-1);
		}
	}
	return ans;
}
long long work(long long p,long long q,long long s){
	long long ans1=0;
	if (p==0){
		return s;
	}
	for (int i=1;i<=n;i++){
		if (i==q){
			continue;
		}
		long long m=work(p-1,q+1,check(a[i],s));
		if (m>=ans1){
			ans1=m;
		}
	}
	return ans1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	if (m==1){
		long long maxn=0;
		for (int i=1;i<=n;i++){
			maxn=max(a[i],maxn);
		}
		cout<<maxn;
	}
	else{
		for (int i=1;i<=n;i++){
			ans=max(ans,work(m-1,i,a[i]));
		}
		cout<<ans;
	}
}
