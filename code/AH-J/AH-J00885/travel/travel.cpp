#include<iostream>
using namespace std;
int main(){
	freopen("and.in","w",stdin);
	freopen("and.in","r",stdout);


	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c) cout<<"1";

	else cout<<"0";
     if(b[0]==c[0] and b[1]==c[1]) cout<<"1";

        else cout<<"0";

    if(b[2]==c[2]) cout<<"1";
        else cout<<"0";

    if(b[2]==68 or b[2]==70){
        if(d[2]==68 or d[2]==70) cout<<"1";
        else cout<<"0";
	}
    else{

            if(d[2]==65 or d[2]==66 or d[2]==67) cout<<"1";
            else cout<<"0";

    }
	return 0;
}
