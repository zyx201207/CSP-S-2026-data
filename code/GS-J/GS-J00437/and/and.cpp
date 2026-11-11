#include<bits/stdc++.h>
using namespace std;
string a;
int cnt=0;
string ttt(int n){
	
	while(n!=0){
		a+=to_string(n%2);
		n=n/2;
		
		cnt++;
		
	}
	string r="";
	for(int i=1;i<=a.size();i++){
		r+=a[a.size()-i];
		
	}
	return r;
	
	
}
int comp(string s1,string s2){

}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	if(m==1){
		cout<<0;
	}
	if(m==2){
		
	}
	cout<<ttt(n);
//	for(int i=0;i<cnt;i++){
//		for(int j=)
//		
//	}
	
	
	
	return 0;
	
} 
