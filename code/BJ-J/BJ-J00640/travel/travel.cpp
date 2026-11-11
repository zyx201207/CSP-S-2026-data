#include<bits/stdc++.h>
using namespace std;
string row1,row2,st1,st2;
int a,b;
char c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>row1>>st1>>row2>>st2;
    if(row1==row2){
        cout<<1;
        int s1s=st1.size(),s2s=st2.size();
        for(int i=s1s-2;i>=0;i--)a=a*10+(st1[i]-'0');
        for(int i=s2s-2;i>=0;i--)b=b*10+(st2[i]-'0');
        if(a==b){
            cout<<1;
            c=st1[s1s-1],d=st2[s2s-1];
            if(((c=='A'||c=='B'||c=='C')&&(d=='A'||d=='B'||d=='C'))||((c=='D'||c=='F')&&(d=='D'||d=='F'))){
                cout<<1;
                if((c=='A'&&d=='B')||(c=='B'&&d=='A')||(c=='B'&&d=='C')||(c=='C'&&d=='B')||(c=='D'&&d=='F')||(c=='F'&&d=='D')){cout<<1;}
                else{cout<<0;}
            }
            else{ cout<<"00";}
        }
        else{ cout<<"000";}
    }
    else{ cout<<"0000";}
    return 0;
}