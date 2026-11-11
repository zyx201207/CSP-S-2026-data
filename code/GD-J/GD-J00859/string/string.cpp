#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m,num=0;
	string k,p="";
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>k;
		for(int j=1;j<=m;j++){
			p+=k;
		}
	}
	int flag=1;
	for(int i=0;i<p.length();i++){
		if(p[i]!=p[p.length()-i-1]){
			flag=0;
			num++;
		}
	}
	num/=2;
	if(flag==1){
		cout<<0;
	}
	else{
		if(num>p.length()-num){
			cout<<p.length()-num;
		}
		else{
			cout<<num;
		}
	}
	return 0;
}
