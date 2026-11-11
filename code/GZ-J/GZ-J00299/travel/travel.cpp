//GZ-J00299,×ñÒåËÄÖÐ£¬Ô¬¼Îòà 
#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,c2,s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		cout<<1;
	    if(s2[0]==c2[0]&&s2[1]==c2[1]){
		    cout<<1;
		    if(s2[2]=='D'&&c2[2]=='F'||c2[2]=='D'&&s2[2]=='F'){
		    	cout<<11;
			}else if(s2[2]!='D'&&c2[2]!='F'&&c2[2]!='D'&&s2[2]!='F'){
				cout<<1;
				if(abs(s2[2]-c2[2])==1){
					cout<<1;
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
	    }else{
		    cout<<"000";
	    }
	}else{
		cout<<"0000";
	}
	return 0;
}
