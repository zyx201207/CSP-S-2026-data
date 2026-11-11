#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string ss;
const ll mmm=2e5+200;
#define rep(i,a,b) for(ll i=a;i<=b;i++)
bool check(ss a1,ss b1,ss a,ss b){
	if(a!=b){
		return 0;
	}
	bool f=1;
	for(ll i=0;i<a1.size()-1;i++){
		if(a1[i]!=b1[i]){
			f=0;
		}
	}
	return f;
}
bool check2(ss a1,ss b1,ss a,ss b){
	bool f=1;
	bool f1=1;
	if(check(a1,b1,a,b)==0){
		return 0;
	}
	for(ll i=2;i<a1.size();i++){
		if(a1[i]>='A'&&a1[i]<='C'){
			f=1;
		}else{
			f=0;
		}
		if(b1[i]>='A'&&b1[i]<='C'){
			f1=1;
		}else{
			f1=0;
		}
	}
	if(f==f1){
		return 1;
	}else{
		return 0;
	}
}
bool check3(ss a1,ss b1,ss a,ss b){
	if(check2(a1,b1,a,b)==0){
		return 0;
	}
	for(ll i=2;i<a1.size();i++){
		if(a1[i]=='B'||b1[i]=='B'){
			return 1;
		}else if(a1[i]=='D'||a1[i]=='F'){
			return 1;
		}else{
			return 0;
		}
	} 
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,a1,b,b1;
	cin>>a>>a1>>b>>b1;
	if(a==b){
		cout<<1;
	}else{
		cout<<0;
	}
	if(check(a1,b1,a,b)){
		cout<<1;
	}else{
		cout<<0;
	}
	if(check2(a1,b1,a,b)){
		cout<<1;
	}else{
		cout<<0;
	}
	if(check3(a1,b1,a,b)){
		cout<<1; 
	}else{
		cout<<0;
	}
	return 0;
} 
