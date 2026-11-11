#include<bits/stdc++.h>
using namespace std;
string s;             
bool pdhw(string v){                       
	int d=v.size();                
	if (d==1) {              
		return 1;                  
	}                                  
	if (d==2){                    
		if (v[0]==v[1]){                   
			return 1;                
		}                 
		else {                   
			return 0;
		}                       
	}              
	if (d==3){                
		if (v[0]==v[2]) return 1;                   
		else return 0;
	}              
	for (int i=0;i<d/2;i++){                  
		if (v[i]!=v[d-i-1]){
			return 0;
		}                                  
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		int x;
		char cc;
		cin>>x>>cc;
		for (int j=1;j<=x;j++){
			s+=cc;
		}
	}
	if (pdhw(s)==1){
		cout<<"0\n";
		return 0;
	}
	if (s.size()%2==0){
		int wd=s.size()/2,cnt=0;
		string sl=s.substr(0,wd);
		reverse(sl.begin(),sl.end());
		int bbb=0;
		for (int i=wd;i<s.size();i++){
			bbb++;
			if (s[i]!=sl[bbb]) cnt++;
		}
		cout<<cnt;
		return 0;
	}
	if (s.size()%2==1){
		int wd=s.size()/2,cnt=0;
		string sl=s.substr(0,wd);
		reverse(sl.begin(),sl.end());
		int bbb=0;
		for (int i=wd+1;i<s.size();i++){
			bbb++;
			if (s[i]!=sl[bbb]) cnt++;
		}
		cout<<cnt;
		return 0;
	}
	else{
		cout<<"ERROR";
	}
	return 0;
} 
