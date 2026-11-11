//华东师范大学附属贵阳学校 刘睿羽 GZ-J00398   
#include<bits/stdc++.h>
using namespace std;
string n,s,m,t;
int f;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s>>m>>t;
    f=4;
    if (n==m) {
    	f=3;
        if (s[0]+s[1]==t[0]+t[1]){
             f=2;
             if ( (('A'<=s[2]&&s[2]<='C')&&('A'<=t[2]&&t[2]<='C'))||(('E'<=s[2]&&s[2]<='F')&&('E'<=t[2]&&t[2]<='F'))){
             	f=1;
             	if (int(s[2]-t[2])==1||int(s[2]-t[2])==-1){
             		f=0;
				 }
			 }
    	}
    }
    int k=4;
    for (int i=1;i<=4;i++){
    	if (k>f)cout<<1;
    	else{
    		cout<<0;
		}
		k--;
	}
    
	return 0; 
}

