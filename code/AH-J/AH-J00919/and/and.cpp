#include<bits/stdc++.h>
using namespace std;
int a[10001];
string ej(int x){
	string s="",s1="";
	while(x!=0){
		s+=(char)x%2+48;
		x/=2;
	}
	for(int i=s.length()-1;i>=0;i--){
		s1+=s[i];
	}
	return s1;
}
string ad(string x,string y){
	string s3="";
	for(int i=(int)min(x.size(),y.size())-1;i>=0;i--){
		if(x[i]=='1'&&y[i]=='1'){
			s3+='1';
		}else{
			s3+='0';
		}
	}
	string sf="";
	for(int i=(int)s3.length()-1;i>=0;i--){
		sf+=s3[i];
	}
	return s3;
}
int sj(string x){
	string s4="";
	for(int i=x.length()-1;i>=0;i--){
		s4+=x[i];
	}
	int c=0;
	long long sum=0;
	for(int i=0;i<(int)s4.size();i++){
		if(s4[i]=='1'){
			sum+=pow(2,c);
		}
		c++;
	}
	return sum;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	int flag=0;
	string s2="";
	if(m==1){
		cout<<a[0];
		return 0;
	}
	long long sum1=0;
	for(int i=1;i<m;i++){
		if(flag==0){
			s2=ad(ej(a[i]),ej(a[i-1]));
			sum1=sj(s2);
			flag=1;
		}else{
			sum1=sj(ad(ej(a[i]),s2));
			s2=ad(ej(a[i]),s2);
		}
	}
	cout<<sum1;
	return 0;
}
