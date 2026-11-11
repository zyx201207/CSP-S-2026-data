#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int sum1=0,sum2=0;
    char a1,a2;
    if(c1==c2){
        cout<<1;
        for(int i=0;i<s1.size();i++){
            if(s1[i]>='0'&&s1[i]<='9'){
                sum1=sum1*10+s1[i];
            }else{
                a1=s1[i];
            }
        }
        for(int i=0;i<s2.size();i++){
            if(s2[i]>='0'&&s2[i]<='9'){
                sum2=sum2*10+s2[i];
            }else{
                a2=s2[i];
            }
        }
        if(sum1==sum2){
            cout<<1;
            if(a1=='A'&&a2=='B'||a1=='B'&&a2=='A'||a1=='B'&&a2=='C'||a1=='C'&&a2=='B'||a1=='A'&&a2=='C'||a1=='C'&&a2=='A'||a1=='D'&&a2=='F'||a1=='F'&&a2=='D'){
                cout<<1;
            }else{
                cout<<0;
            }
            if(a1=='A'&&a2=='B'||a1=='B'&&a2=='A'||a1=='B'&&a2=='C'||a1=='C'&&a2=='B'||a1=='D'&&a2=='F'||a1=='F'&&a2=='D'){
                cout<<1;
            }else{
                cout<<0;
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }

    return 0;
}
