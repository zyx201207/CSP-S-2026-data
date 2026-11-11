#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,s1;
    string c2,s2;
    cin>>c1>>c2>>s1>>s2;
    bool m=false,n=false;
    for(int i=1;i<=1;i++){
        if(c1!=s1){
            cout<<"0000"<<endl;;
            break;
        }
        else{
            cout<<"1";
            if(c2[0]==s2[0]&&c2[1]==s2[1]){
                    cout<<"1";
                if(c2[2]=='D'&&s2[2]=='F'){
                    m=true;
                }
                else if(c2[2]=='A'&&s2[2]=='B'){
                    m=true;
                }
                else if(c2[2]=='A'&&s2[2]=='C'){
                    m=true;
                }
                else if(c2[2]=='B'&&s2[2]=='C'){
                    m=true;
                }
                if(m==true){
                    cout<<"1";
                    if(c2[2]=='D'&&s2[2]=='F'){
                        n=true;
                    }
                    else if(c2[2]=='B'&&s2[2]=='C'){
                        n=true;
                    }
                    else if(c2[2]=='A'&&s2[2]=='B'){
                        n=true;
                    }
                    if(n==true){
                        cout<<"1"<<endl;
                    }
                    else{
                        cout<<"0"<<endl;
                    }
                }
                else if(m==false){
                    cout<<"00"<<endl;
                    break;
                }
            }
            else{
                    cout<<"000"<<endl;
                    break;
                }
            }
        }
    return 0;
}
