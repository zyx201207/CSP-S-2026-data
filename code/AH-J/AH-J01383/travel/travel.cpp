#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int a,b;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
        cout<<"1";
        a=s1[0]-'0'+s1[1]-'0';
        b=s2[0]-'0'+s2[1]-'0';
        if(a==b){
        cout<<"1";
        a=s1[2];b=s2[2];
            if(a<=67&&b<=67||a>=68&&b>=68) {
                cout<<"1";
                if(a-b==1&&a!=68||b-a==1&&b!=68) cout<<"1";
            else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
	}else{
		cout<<"0000";
	}

	return 0;
}
