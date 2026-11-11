#include<bits/stdc++.h>

using namespace std;
int main(){
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    cin>>n;
    cin>>m;
    int a[m];
    for(int i=0;i<=n;i++){
        cin>>a[i]
    }
    string c1 , s1 , c2 , s2;
    int cnt1=0;
    int cnt=0;
    cin>>c1;
    cin>>s1;
    cin>>c2;
    cin>>s2;


    if(c1==c2){
        cout<<1;

        if(s1[1]==s2[1]){
            cout<<1;
            cnt=1;
        }
        else;
            cnt=0;
            cout<<cnt;
        if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
            if(s1[2]=='D'||s1[2]=='F'){
                cout<<0;
                cnt1=0;
            }
            else;
                cnt1=1;

        }
        cout<<cnt1;
        if(cnt1){
            if(s1[2]=='A'||s1[2]=='B'&&s2[2]=='A'||s2[2]=='B')
                cout<<1;
            if(s1[2]=='B'||s1[2]=='C'&&s2[2]=='B'||s2[2]=='C')
                cout<<1;
            if(s1[2]=='D'||s1[2]=='F'&&s2[2]=='D'||s2[2]=='F')
                cout<<1;
        }

    }





    return 0;
}
