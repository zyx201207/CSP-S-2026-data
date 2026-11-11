#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.in","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string c1,c2,s1,s2;
    cin>>c1>>c2>>s1>>s2;
    string str=" ";
    string sd=" ";
    int ai=c2[3];
    int ci=s2[3];
    for(int i=1;i<=2;i++){
        str+=c2[i];
    }
    for(int j=1;j<=2;j++){
        sd+=s2[j];
    }
    while(('01'<=c1&&c1<='17'&&c1!='16')&&('01'<=s1&&s1<='17'&&s1!='16')){
        if(c1==s1){
            if(c2==s2){
                cout<<1111;
                return 0;
            }
            else{
                if(str!=sd){
                    cout<<1010;
                    return 0;
                }
                else{
                    while(('A'<=ai&&ai<='F'&&ai!='E')&&('A'<=ci&&ci<='F'&&ci!='E')){
                        if('A'<=ai&&'A'<=ci&&ai<='C'&&ci<='C')||('D'<=ai&&'D'<=ci&&ai<='F'&&ci<='F')&&(ai-ci-'0'==0){
                            cout<<0101;
                            return 0;
                        }
                        else cout<<0000;
                    }
                }
            }
        }
        else{
            if(c2==s2){
                cout<<0101;
                return 0;
            }
            else{
                cout<<0000;
                return 0;
        }
    }
}
}