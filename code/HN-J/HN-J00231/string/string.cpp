#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e7+10;
ll n,m,num,a[N];
string reverse_(string x){
	string y;
	for(int i=x.size()-1;i>=0;i--){
		y+=x[i];
	}//O(slen)
	return y;
}
string s,s1;
void zj(int x,char y){
	for(int i=1;i<=x;i++){
		s+=y;
	}
}
void gg(int x){
	//cout<<s<<" "<<s1;
	s[s.size()-x-1]=s[x];
	s1[x]=s1[s1.size()-x-1];
	//cout<<"   "<<s<<" "<<s1<<"\n";
	num++;
	//s=aabbc
	//s1=cbbaa
	//s=aabba
	//s1=abbaa
	//s=aabaa
	//s1=aabaa
}
ll t[30];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int x;char c;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		zj(x,c);
		//t[c-'a'+1]+=x;
	}//O(n*x)
	s1=reverse_(s);
	for(int i=0;i<s.size();i++){
		if(s==s1)break;
		if(s[i]!=s1[i]){
			gg(i);
		}
	}//O(n*x)
	cout<<num;
	//s=aabbc
	//s1==cbbaa
	return 0;
}
//¸´ÔÓ¶È
//O(2*n*x+s.size())
//O(1000000000*2*2*100000+1000000000*100000)
//O(400000000000000+100000000000000)
//O(500000000000000)
//O(5*10^14)
//12*4~14*4
//·Ö48~56 
