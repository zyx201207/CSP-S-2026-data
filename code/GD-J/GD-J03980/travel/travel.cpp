#include <bits/stdc++.h>
using namespace std;
bool check(string a,string b){
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]){
			return false;
		}
	}
	return true;
}
bool check2(string x,string y){
	for(int i=0;i<x.size()-1;i++){
		if(x[i]!=y[i]){
			return false;
		}
	}
	return true;
}
bool check3(string a,string b){
	int cnt=a.size();
	for(int i=0;i<cnt-1;i++){
		if(a[i]!=b[i]){
			return false;
		}
	}
	int ans1,ans2;
	ans1=a[cnt-1];
	ans2=b[cnt-1];
	if((ans1>='A' && ans1<='C' && ans2>='A' && ans2<='C' && ans1!=ans2) || (ans1>='D' && ans1<='F' && ans2>='D' && ans2<='F' && ans1!=ans2)){
		return true;
	}
	return false;
}
bool check4(string x,string y){
	int cnt=x.size();
	for(int i=0;i<cnt-1;i++){
		if(x[i]!=y[i]){
			return false;
		}
	}
	int ans1,ans2;
	ans1=x[cnt-1]-'A';
	ans2=y[cnt-1]-'A';
	if(ans1-ans2==1 || ans2-ans1==1){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	cout<<check(s1,s3)<<check2(s2,s4)<<check3(s2,s4)<<check4(s2,s4)<<endl;
	return 0;
}
