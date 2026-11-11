#include<bits/stdc++.h>
using namespace std;
string a1,b1,c1,d1;
int n,m,p,q;
int  aaa(string a,string c){
	if(a.size()!=c.size()){
		cout<<"0";
		return n;
	}
	int cnt=0;
	if(a.size()==c.size()){
		for(int i=0;i<a.size();i++){
			if(a[i]==c[i]){
				cnt++;
			}
		}
		if(cnt==a.size()){
			cout<<"1";
			return 1;
		}else{
			cout<<"0";
		
			return n;
		}
	}	
}
int  aab(string a,string c){
	
		if(a.size()!=c.size()){
			cout<<"0";
			return m;
		}
		int cnt=0;
		int len =a.size()-1;
		if(a.size()==c.size()){
			for(int i=0;i<len;i++){
				if(a[i]==c[i]){
					cnt++;
				}
			}
			if(cnt==len){
				cout<<"1";
				return 1;
			}else{
				cout<<"0";
			
				return m;
			}
		}	
	
}
	
int aac(string b,string d){
	
		if(b.size()!=d.size()){
			cout<<"0";
			return p;
		}
		int len=b.size();
		if((b[len-1]<=67)&&(d[len-1]<=67)||(b[len-1]>67)&&(b[len-1]<=69)&&(d[len-1]>67)&&(d[len-1]<=69)){
			cout<<"1";
		}else{
			cout<<0;
		
			return p;
		}
	
}
int aad(string b,string d){
	
		if(b.size()!=d.size()){
			cout<<"0";
		}
		int len=b.size();
		if(abs(b[len-1]-d[len-1])==1){
			cout<<"1";
		}else cout<<"0";
	
}
int main(){
	freopen("travel.in",r,stdin);
	freopen("travel.out",r,stdout);
	cin>>a1>>b1>>c1>>d1;
	if(aaa(a1,c1)){	
		if(aab(b1,d1)){
			if(aac(b1,d1)){
				aad(b1,d1);
			}else cout<<"0";
		}else cout<<"00";
	}else cout<<"000";
	

	return 0;
}
