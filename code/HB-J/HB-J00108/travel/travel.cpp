#include<bits/stdc++.h>

using namespace std;

int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    char str1[50],str2[50];
    cin>>a>>str1>>b>>str2;
    if(a!=b){
        cout<<"0000";
    }
    else{
        if(str1[0]!=str2[0]||str1[1]!=str2[1]){
            cout<<"1000";
        }
        else{
            if(str1[2]>='D'&&str2[2]<='C'){
                cout<<"1100";
            }
            else if(str2[2]>='D'&&str1[2]<='C'){
                cout<<"1100";
            }
            else{
                if(str1[2]>='D'){
                    cout<<"1111";
                }
                else{
                    if(abs(str1[2]-str2[2])==2){
                        cout<<"1110";
                    }
                    else{
                        cout<<"1111";
                    }
                }
            }
        }
    }
    return 0;
}
