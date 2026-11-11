#include <bits/stdc++.h>
using namespace std;

string c1,c2,s1,s2;
string R1,X1;
char R2=' ';
char X2=' ';
void seat(string s1,string s2){
        cin>>s1>>s2;
        for(int i=0;i<=1;i++){
            R1=R1+s1[i];
        }
        R2=s1[2];
        for(int i=0;i<=1;i++){
            X1=X1+s2[i];
        }
        X2=s2[2];
        }

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;

    int a[4]={0,0,0,0,};
    if(c1==c2){
         a[0]=1;
        seat(s1,s2);
        int m=R2-'0'+48,n=X2-'0'+48;
        if(R1==X1){
             a[1]=1;
        if((m>=97&&m<=99)&&(n>=97&&n<=99)||((m>=100&&m<=102)&&(n>=100&&n<=102)))
           {a[2]=1;
        if(m-n==1||n-m==1)
                 a[3]=1;}}
        else{
        for(int i=1;i<=4;i++)
            cout<<a[i];
    }
    for(int i=0;i<4;i++){
        cout<<a[i];}

return 0;}}
