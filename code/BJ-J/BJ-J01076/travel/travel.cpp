#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int a=0,k1=0,k2=0;
    cin>>c1>>s1>>c2>>s2;
    char w1=s1[2],w2=s2[2];
    if(c1==c2){
        cout<<"1";
        for(int i=0;i<2;i++){
                int k1=0,k2=0;
                k1+=s1[i];
                k2+=s2[i];
                if(k1==k2)
                    a++;
        }
        if(a==2){
            cout<<"1";
            if((w1=='D'&&w2=='F')||(w1=='F'&&w2=='D')){
                cout<<"11";
            }
            else if((w1=='A'&&w2=='B')||(w1=='B'&&w2=='A')||(w1=='A'&&w2=='C')||(w1=='C'&&w2=='A')||(w1=='B'&&w2=='C')||(w1=='C'&&w2=='B')){
                cout<<"1";
                if((w1=='A'&&w2=='B')||(w1=='B'&&w2=='A')||(w1=='C'&&w2=='B')||(w1=='B'&&w2=='C')){
                    cout<<"1";
                }
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}