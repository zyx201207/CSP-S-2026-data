#include<bits/stdc++.h>
using namespace std;
int n,m,a[200002];
string th2[2000002]; 
string into2(int x){
	string anss,ansst;
	int temp=0;
	while(x!=1){
		if(x%2==0){
			ansst+='0';
		}else{
			ansst+='1';
		}
		temp++;
		x/=2;
	}
	temp++;
	ansst+='1';
	int siz=ansst.size();
	for(int i=temp-1;i>=0;i--){
		anss+=ansst[i];
	}
	return anss;
}
int into1(string x){
	int ans=0;
	int siz=x.size();
	for(int i = 0;i<siz;i++){
		if(x[siz-1-i]!='0')ans+=pow(2,i);
	}
	return ans;
} 
int and2(string s1,string s2){
	string ans;
	int siz1=s1.size();
	int siz2=s2.size();
	int s12=0;
	int s21=0;
	if(siz1>siz2){
		s12=siz1-siz2;
		
	}siz1=siz2;
	for(int i = 0;i<siz1;i++){
		if(s1[i]==s2[i]&&s1[i]=='1')ans+='1';
		else ans+='0';
	}
	
}
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	//string k=into2(n);
	//cout<<k.size()<<" "<<k<<" "<<into1(k);
	for(int i=0;i<n;i++){
		cin>>a[i];
		th2[i]=into2(a[i]);
	}
	sort(a,a+n);//shengxu
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	for(int i = 0;i<n;i++;){
		
	}
	return 0;
}
