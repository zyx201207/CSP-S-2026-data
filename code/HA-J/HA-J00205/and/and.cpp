#include<bits/stdc++.h>
using namespace std;
int n,m;
int r;
string two(int number){
	string s,s1;
	int x;
	while(number!=0){
		x=number%2;
		s+=char(x+'0');
		number/=2;
	}
	return s;
}
int pf(int c){
	int a=1;
	for(int i=1;i<=c;i++){
		a*=2;
	}
	return a;
}
int answer(int n1,int n2){
	string s1=two(n1);
	string s2=two(n2);
	string a;
	int answer=0;
	for(int i=0;i<min(s1.size(),s2.size());i++){
		if(s1[i]==s2[i]) {
			a+='1';
		}else{
			a+='0';
		} 
	}
	for(int i=0;i<a.size();i++){
		answer+=(int(a[i])-'0')*pf(i);
	}
	return answer;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long a[n]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			r=max(r,answer(a[i],a[j]));
		}
	}
	cout<<r;
	return 0;
}

