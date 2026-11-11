#include<bits/stdc++.h>
using namespace std;
int c1,c2;
char p1,p2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    p1=s1[2];
    p2=s2[2];
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            if((p1=='A'&&p2=='B')||(p1=='A'&&p2=='C')||(p1=='B'&&p2=='A')||(p1=='B'&&p2=='C')||(p1=='C'&&p2=='A')||(p1=='C'&&p2=='A')||(p1=='D'&&p2=='F')||(p1=='F'&&p2=='D')){
                cout<<1;
                if((p1=='A'&&p2=='B')||(p1=='B'&&p2=='A')||(p1=='B'&&p2=='C')||(p1=='C'&&p2=='B')||(p1=='D'&&p2=='F')||(p1=='D'&&p2=='F')){
                   cout<<1;
                }
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
    fclose(stdin);
    fclose(stdout);
}
