#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[200001]={};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	string s="";
	while(a[0]!=0){
		if(a[0]%2==1){
			s+='1';
		}else{
			s+='0';
		}
		a[0]/=2;
	}
	for(int i=1;i<m;i++){
		long long l=a[i];
		string s1;
		while(a[i]!=0){
			if(a[i]%2==1){
				s1+='1';
			}else{
				s1+='0';
			}	
			a[i]/=2;
		}
		string s2;
		for(int j=0;j<min(s.length(),s1.length());j++){
			if(s[j]=='1'&&s1[j]=='1'){
				s2+='1';
			}else{
				s2+='0';
			}
		}
		s=s2;
	}
	long long num=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='1'){
			num+=pow(2,i);
		}
	}
	cout<<num;
	return 0;
}
