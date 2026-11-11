#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int n=2,m=3,ans=0;
	for(int i=0;i<n;i++){
		if(c1[i]==c2[i]){
			ans++;
		}
		else{
			cout<<"0000";
			return 0;
		}
	}
	if(ans==n){
		cout<<1;
	}
	ans=0;
	for(int i=0;i<m-1;i++){
		if(s1[i]==s2[i]){
			ans++;
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	if(ans==m-1){
		cout<<1;
	}
	if((s1[m-1]<='C'&&s2[m-1]<='C')||(s1[m-1]>='D'&&s2[m-1]>='D')){
		cout<<1;
	} 
	else if(s1[m-1]=='C'&&s2[m-1]=='D'){
		cout<<"00";
		return 0; 
	}
	else{
		cout<<0;
	}
	if((s1[m-1]+1==s2[m-1])||(s2[m-1]+1==s1[m-1])){
	    	cout<<1; 
	}
	else{
		cout<<0;
	}
	return 0;
} 
