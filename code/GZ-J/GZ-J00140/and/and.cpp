//GZ-J00140，石光轩，观山湖区第九中学 
#include<bits/stdc++.h>
using namespace std;
long long pw(int m){
	long long x=1;
	if(m==0){
		return 0;
	}
	for(int i=1;i<=m;i++){
		x*=2;
	}
	return x;
}
string f(long long n){
	string e;
	int m=0;
	while(true){
		if(n==1){
			e+='1';
			m+=1;
			break;
		}else if(n==0){
			break;
		}
		if(n%2==0){
			n=n/2;
			m+=1;
			e+='0';
		}else{
			n=n/2;
			m+=1;
			e+='1';
		}
	} 
	string s1;
	for(int i=m;i>=0;i--){
		s1+=e[i];
	}
	return s1;
}
string an(long long a,long long b){
	string s;
	string a1=f(a);
	string b1=f(b);
	int n=a1.size()-1;
	int m=b1.size()-1;
	int len;
	if(n>m){
		len=m;
	}else{
		len=n;
	}
	for(int i=len-1;i>=0;i--){
		if(a1[i]==b1[i]){
			s+='1';
		}else{
			s+='0';
		}
	}
	return s;
}
long long zh(string a){
	int n=a.size()-1;
	long long fh=0;
	for(int i=0;i<=n;i++){
		fh+=(a[i]-'0')*pw(i);
	}
	return fh;
}



int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,x,len;
	cin>>n>>m;
	long long s[n+5],s1[n+5];
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			s1[i]=zh(an(s[i],s[j]));
			len+=1;
		}
		
	}
	x=0;
	for(int i=0;i<len;i++){
		if(x<s1[i]){
			x=s1[i];
		}
	}
	cout<<x;
	
	
	
	return 0;
}
