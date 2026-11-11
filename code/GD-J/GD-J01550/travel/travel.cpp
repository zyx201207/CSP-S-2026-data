#include <bits/stdc++.h>
using namespace std;
string a,aa,b,bb,ans="";
int pd[6]={1,2,1,3,3};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a>>aa>>b>>bb;
	if(a==b){
		ans+='1';
		if(aa[0]==bb[0]&&aa[1]==bb[1]){
		    ans+='1';
		    if((pd[aa[2]-'A']+pd[bb[2]-'A'])<=3){
		    	ans+='1';
		    	if((pd[aa[2]-'A']+pd[bb[2]-'A'])%3==0){
		    		ans+='1';
				}else{
					ans+='0';
				}
			}else{
				ans+='0';
				ans+='0';
			}
	    }else{
	    	ans+='0';
	    	ans+='0';
	    	ans+='0';
		}
	}else{
		ans="0000";
	}
	cout<<ans;
	return 0;
}
