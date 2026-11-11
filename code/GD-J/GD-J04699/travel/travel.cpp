#include <bits/stdc++.h>
using namespace std;
int c_1,c_2;
string s_1,s_2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","l",stdout);
	cin>>c_1>>s_1>>c_2>>s_2;
	
	if(c_1!=c_2){
		cout<<"0000";
		return 0;
	}
	else{
		int n,m;
		n=int(int(s_1[0])-'0')*10+(int(s_1[0])-'0');
		m=int(int(s_2[0])-'0')*10+(int(s_2[0])-'0');
		if(n!=m){
			cout<<"1000";
			return 0; 
		}
		else{
			char a,b;
			a=s_1[2];
			b=s_2[2];
			if(a==b+1 || a==b-1){
				cout<<1111;
				return 0;
			}
			else if((a>='A' && a<='C') && (b>='A' && b<='C')
			 || (a>='D' && a<='F') && (b>='D' && b<='F')){
			 	cout<<1110;
			 	return 0;
			 }
			 else{
			 	cout<<1100;
			 	return 0;
			 }
		}
		
	}
	
	return 0;
}
