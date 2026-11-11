#include <bits/stdc++.h>
using namespace std;
long long sum=0;
string s1,s2,s,mm;
	bool f=0;
string aa(long long nn){
	string m;
	for(int j=0;j<nn;j++){
			m+=mm;
		}
		return m;
}
string jie(int a,int b){
	string n;
	for(int i=a;i<b;i++){
		n+=s[i];
	}
	return n;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m>>mm;
		if(m%1000==0){
			m/=1000;
			f=1;
	}
		s+=aa(m);
	}
	s1=jie(0,s.size()/2);
	if(s.size()%2!=0) s2=jie(s.size()/2,s.size()-1);
	else s2=jie(s.size()/2,s.size());
	for(int i=0;i<s.size()/2;i++){
		if(s1[i]!=s2[i])sum++;
	}
	if(f){
		cout<<sum*1000;
	}else{
		cout<<sum;
	}
	return 0;
}
