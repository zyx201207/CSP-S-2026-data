#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000005];
long long zdz[10000005]={-1};
string ejz(long long  b){
	long long  d=b;
	string s;
	while(d>0){
		s+=d%2+'0';
		d/=2;
	}
	reverse(s.begin(),s.end());
	return s;
}
string awy(string s1,string s2){
	if(s1.size()<s2.size()){
		reverse(s1.begin(),s1.end());
		for(long long  i=1;i<=(long long)s2.size()-(long long)s1.size();i++){
			s1+='0';
		}
		reverse(s1.begin(),s1.end());
	}else{
		reverse(s2.begin(),s2.end());
		for(long long i=1;i<=(long long)s1.size()-(long long)s2.size();i++){
			s2+='0';
		}
		reverse(s2.begin(),s2.end());
	}
	string x="";
	for(long long i=0;i<(long long)s1.size();i++){
		if(s1[i]!=s2[i]) x+='0';
		else x+='1';
	}
	return x;
}
long long ezs(string ss){
	reverse(ss.begin(),ss.end());
	long long sum=0;
	for(long long i=0;i<(long long )ss.size();i++){
		sum+=(ss[i]-'0')*pow(2,i);
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","W",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=m;i++){
		for(long long j=1;j<=n;j++){
			zdz[i]=max(zdz[i],a[j]);
		}
		for(long long  j=1;j<=n;j++){
			if(zdz[i]==a[j]){
				a[j]=0;
				break;
			}
		}
	}
	//cout << ezs(awy(ejz(15),ejz(12)));
	long long da=zdz[1];
	for(long long i=2;i<=m;i++){
		da=ezs(awy(ejz(da),ejz(zdz[i])));
	}
	cout << da;
	return 0;
}
