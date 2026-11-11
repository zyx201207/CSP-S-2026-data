#include<bits/stdc++.h>
using namespace std;
int ans,n,t;
string a,s;
int hw(string d){
	int c=d.size()-1,flag=0;
	for(int i=0;i<=c;i++){
		if(d[i]!=d[c-i]){
			flag=1;
			break;
		}
	}
	if(flag==0){
		return true;
	}else{
		return false; 
	}
}
int fix(string f){
	int cnt=0;
	int l=f.size()-1;
	for(int i=0;i<=l;i++){
		if(f[i]!=f[l-i]){
			cnt++;
		}
	}
	return cnt/2;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t>>a;
		for(int i=1;i<=t;i++){
			s+=a;
		}
	}
	if(hw(s)==true){
		cout<<0;
	}else{
		cout<<fix(s);
	}
	return 0;
}
