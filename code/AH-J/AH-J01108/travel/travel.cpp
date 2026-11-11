#include<iostream>
#include<string>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c,cd,s,sd;
    cin>>c>>cd>>s>>sd;
    if(c[0]!=s[0]||c[1]!=s[1]){
        cout<<"0000";
    }
    else{
        if(cd[0]!=sd[0]||cd[1]!=sd[1]){
            cout<<"1000";
        }
        else {
            if(cd[2]>='A'&&cd[2]<='C'){
                if(sd[2]>='D'){
                    cout<<"1100";
                }
                else{
                    if(cd[2]!='B'&&sd[2]!='B'){
                        cout<<"1110";
                    }
                    else cout<<"1111";
                }
            }
            else if(cd[2]>='D'&&cd[2]<='F'){
                if(sd[2]<='C'){
                    cout<<"1100";
                }
                else cout<<"1111";
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
