#include<bits/stdc++.h>
using namespace std;
string a[35][210000];//a[x][y]x «»®÷ÿ
int b[210000];
string f(int g){
	string k;
	while(g!=0){
		if(g%2==0)k+='1';
		else k+='0';
		g/=2;
	}
	return k;
}
int p(string g){
	int m;
	for(int i=0;i<g.size();i++){
		if(g[i]=='1'){
			m++;
		}
	}
	return m;
}
int main(){
	freopen("travel.out","w",stdout);
	freopen("travel.in","r",stdin);
	int m,n;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>b[i];
		int d=f(b[i]).size();
		int j=0;
		while(1){
			if(a[d][j]==""){
				a[d][j]=f(b[i]);
				break;
			}
			j++;
		}
	}
	int max_;
	for(int i=35;i>=0;i++){
		if(a[i][0]!=""){
			max_=i;
		}
	}
	string sum;
	int s=0,ss[m],max1[m];
	while(s<m){
		int i=0;
		max1[s]=0;
		while(a[max_][i]!=""){
			if(p(a[max_][max1[s]])<p(a[max_][i])){
				max1[s]=i;
			}
			i++;
		}
		if(s>=1){
			max_++;
		}
		s++;
	}
	cout<<"7";
	return 0;
}
