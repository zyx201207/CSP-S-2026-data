#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=1;i<=c1.size();i++){
		if(c1[i]==c2[i]){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	for(int j=1;j<=s1.size();j++){
		if(s1[j]!='D'){
		    if(s1[j]!=s2[j]&&s1[j]-s2[j]=='1'){
			    cout<<1;
		    } 
		else{
			cout<<0;
		    }
	    }
    }
	return 0;
	 
}
