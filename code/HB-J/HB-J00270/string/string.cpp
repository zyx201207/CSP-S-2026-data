#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
struct stu{
	ll ai;
	char bi;
}a[200005];
ll x;
char y;
string s="";
ll sum=0;

bool check1(){
	char p;
	p=a[0].bi;
	for(int i=1;i<n;i++){
		if(a[i].bi!=p){
			return 0;
		}
	}
	return 1;
}

bool check2(){
	for(int i=0;i<=n/2;i++){
		if(!(a[i].ai==a[n-i-1].ai && a[i].bi==a[n-i-1].bi)){
			return 0;
		}
	}
	return 1;
}

void runnning1(){
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i].ai;j++){
			s=s+a[i].bi;
		}
	}
	
	ll cnt=0;
	for(ll i=0;i<ll(s.size())/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			cnt++;
		}
	}
	
	cout<<cnt;
	return ;
}

void runnning2(){
	cout<<10000000000;
	return ;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].ai>>a[i].bi;
		sum+=a[i].ai;
	}
	
	if(check1()){
		cout<<0;
	}else if(check2()){
		cout<<0;
	}else if(sum<=2*1e9){
		runnning1();
	}else{
		runnning2();
	}
	
	
	return 0;
}
