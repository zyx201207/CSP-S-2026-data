#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	int len=b.size();
	if(a==c){
	    cout<<"1";
	    string b1="",d1="";
	    for(int i=0;i<len-1;i++){
		    b1+=b[i];
		    d1+=d[i];
    	}
    	if(b1==d1){
		    cout<<"1";
		    char b2,d2;
		    b2=b[len-1],d2=d[len-1];
		    if(b2<='C'&&d2>='D') cout<<"00";
		    else{
		    	cout<<"1";
		    	if(b2+1==d2) cout<<"1";
		    	else cout<<"0";
			}
		}
	    else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
