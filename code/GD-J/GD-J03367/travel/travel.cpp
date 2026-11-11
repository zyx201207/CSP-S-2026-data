#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel4.in","r",stdin);
	freopen("travel4.out","w",stdout); 
	int a1,b1;
    string a2,b2;
    cin>>a1;
    cin>>a2;
    cin>>b1;
    cin>>b2;
    int q=0,w=0,e=0,r=0;
    if(a1==b1){
        q=1;
        if(a2[0]==b2[0]&&a2[1]==b2[1]){
            w=1;
            if((a2[2]>='A'&&a2[2]<='C')&&(b2[2]>='A'&&b2[2]<='C')){
                e=1;
                if((a2[2]=='A'||b2[2]=='A')&&(a2[2]=='C'||b2[2]=='C')){
                    r=0;
                }else{
                    r=1;
                }
            }else if((a2[2]=='d'||b2[2]=='d')&&(a2[2]=='e'||b2[2]=='e')){
                e=1;
                r=1;
            }
        }
    }
    cout<<q<<w<<e<<r;
}
