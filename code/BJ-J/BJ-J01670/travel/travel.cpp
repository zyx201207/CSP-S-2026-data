#include<bits/stdc++.h>
using namespace std;
bool ans(string s1,string s2){
    int a1=s1[2]-'A';
    int a2=s2[2]-'A';
    if(a1>=0&&a1<=2&&a2>=0&&a2<=2||a1<=5&&a2<=5&&a1>=3&&a2>=3)return true;
    return false;
}
bool sum(string s1,string s2){
    int a1=s1[2]-'A';
    int a2=s2[2]-'A';
    if(min(a1,a2)==3&&max(a1,a2)==5||abs(a1-a2)==1)return true;
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;

    int a1=(s1[0]-'0')*10+(s1[1]-'0');
    int a2=(s3[0]-'0')*10+(s3[1]-'0');
    int b1=(s2[0]-'0')*10+(s2[1]-'0');
    int b2=(s4[0]-'0')*10+(s4[1]-'0');
    if(a1==a2){
        cout<<'1';
        if(b1==b2){
            cout<<'1';
            if(ans(s2,s4)){
                cout<<'1';
                if(sum(s2,s4)){
                    cout<<'1';
                }
                else{
                    cout<<'0';
                }
                cout<<endl;
            }
            else{
                cout<<"00"<<endl;
            }
        }
        else{
            cout<<"000"<<endl;
        }
    }
    else{
        cout<<"0000"<<endl;
    }
    return 0;
}
