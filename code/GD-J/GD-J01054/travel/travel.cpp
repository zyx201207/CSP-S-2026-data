#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool pd(string x,string y){
	if((x[2]=='C'&&y[2]=='D')||(x[2]=='D'&&y[2]=='C')){
		return false;
	}
	if(x[2]+1==y[2]||x[2]-1==y[2]) return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else cout<<0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&(c1==c2)){
		cout<<1;
	}else cout<<0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&(c1==c2)){
		if(s1[2]<=67&&s2[2]<=67){
			cout<<1;
		}else if(s1[2]>67&&s2[2]>67){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&(c1==c2)){
		if(pd(s1,s2)){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
} 
