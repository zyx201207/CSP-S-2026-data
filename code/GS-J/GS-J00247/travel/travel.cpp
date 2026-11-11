#include<iostream>
using namespace std;
int main(){
    freopen("travel.in","r",std::in);
    freopen("travel.out","w",std::out);
    int a,b;
    char aa[2],bb[2];
    cin>>a>>aa[0]>>aa[1]>>b>>bb[0]>>bb[1];
    if(a!=b)cout<<"0000";
    else {
        cout<<"1";
        if(aa[0]!=bb[0]||aa[1]!=bb[1]){
            cout<<"000"<<endl;
            return 0;
        }
        else{
            cout<<"1";
            if(aa[2]<='C'){
                if(bb[2]>c){
                    cout<<"00"<<endl;
                    return 0;
                }
                else{
                    cout<<"1";
                    if(aa[2]=='B'||bb[2]=='B'){
                        cout<<"1";
                        return 0;
                    }
                    else{
                        cout<<'0';
                        return 0;
                    }
                }
            }
            else if(aa[2]>'C'){
                if(bb[2]<='C'){
                    cout<<"00"<<endl;
                    return 0;
                }
                else{
                    cout<<"11"<<endl;
                }
            }
        }
    }
    return 0;
}