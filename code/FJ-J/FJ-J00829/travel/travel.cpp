#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<s1.size();i++){
		for(int j=0;j<s2.size();j++){
			if(c1==c2){
				cout<<1;
			    if(s1[1]==s2[1]&&s1[2]==s2[2]){
				    cout<<1;
				    s1[3]=s1[3]-'A';
				    s2[3]=s2[3]-'A';
				    if((s1[3]<3&&s2[3]<3)||(s1[3]>=3&&s2[3]>=3)){
				    	cout<<1;
				    	if(s1[3]+1==s2[3]||s2[3]+1==s1[3])cout<<1;
				    	else cout<<0;
					}
					else cout<<00;
			    }
			    else cout<<000;
			}
			else cout<<0000;
		}
	}
	return 0;
}
