#include<bits/stdc++.h>
using namespace std;
int n,n1,m,m1;
char t,n2,m2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>t;n=(t-'0')*10;
    cin>>t;n+=(t-'0');
    cin>>t;n1=(t-'0')*10;
    cin>>t;n1+=(t-'0');cin>>n2;
    cin>>t;m=(t-'0')*10;
    cin>>t;m+=(t-'0');
    cin>>t;m1=(t-'0')*10;
    cin>>t;m1+=(t-'0');cin>>m2;

    if(n==m){
        if(n1==m1){
            if(m2=='D'||m2=='F'){
                if(n2=='D'||n2=='F')cout<<"1111";
                else cout<<"1100";
            }else{
                if(n2=='D'||n2=='F')cout<<"1100";
                else{
                    if((m2=='A'&&n2=='C')||(m2=='C'&&n2=='A'))cout<<"1110";
                    else cout<<"1111";
                }
            }
        }else{
            cout<<"1000";
        }
    }else cout<<"0000";

    return 0;
}
// I Love XLF