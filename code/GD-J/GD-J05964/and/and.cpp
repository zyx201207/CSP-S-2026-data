#include<bits/stdc++.h>
using namespace std;
string E(int a){
	string s="";
	while(a!=0){
		char d=a%2+'0';
		s=d+s;
		a/=2;
	}
	return s;
}
int S(string a){
	int sum=0;
	for(int i=0;i<a.length();i++){
		sum+=pow(2,a.length()-i-1)*int(a[i]-'0');

	}
	return sum;
}
int A(int a,int b){
	string s=E(a);
	string q=E(b);
	string d="";
	if(s.length()<q.length()){
		swap(s,q);
	}
	for(int i=q.length();i<s.length();i++){
		q='0'+q;

	}
	for(int i=0;i<s.length();i++){
		int w1=s[i]-'0';
		int w2=q[i]-'0';
		if(w1&&w2){
			d=d+'1';
			
		}
		else{
			d=d+'0';
		}
	}

	return S(d);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005]={};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	int sum=0,max=-1;
	for(int i=1;i<=n-m;i++){
		sum=a[i];
		for(int j=1;j<=m;j++){
			sum=A(sum,a[i+j]);
		}
		if(sum>max){
			max=sum;
		}
	}
	cout<<max;
	return 0;
} 
