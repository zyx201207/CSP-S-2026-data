#include<iostream>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        string t1=s1.substr(0,2),t2=s2.substr(0,2);
        if(t1==t2){
            cout<<"1";
            char p1=s1[2],p2=s2[2];
            if(p1=='A'&&p2=='B'||p1=='B'&&p2=='C'||p2=='A'&&p1=='B'||p2=='B'&&p1=='C'){
                cout<<"11";
            }else if(p1=='D'&&p2=='F'||p1=='F'&&p2=='D'){
                cout<<"11";
            }else if(p1=='A'&&p2=='C'||p2=='A'&p1=='C'){
                cout<<"10";
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
