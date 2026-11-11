#include <bits/stdc++.h>
using namespace std;
int y=0,e=0;
vector<string>b;
vector<char>q;
int yan(char x,char y){
    int n=0;
    for(int i=0;i<b.size();i++)
    {
        if(x==b[i][0] && y==b[i][1]) {n=1;}
    }
    if(n==1) {return 1;}
    return 0;
}
int lin(char x,char y){

        if(x=='A'){
            if (y=='C'){return 1;}
            if (y=='B'){return 2;}
        }
        if(x=='B'){
            if (y=='C'||y=='A'){return 2;}
        }
        if(x=='C'){
            if (y=='A'){return 1;}
            if (y=='B'){return 2;}
        }
        if(x=='D'){
            if (y=='F'){return 2;}
        }
        if(x=='F'){
            if (y=='D'){return 2;}
        }
        return 0;

}
int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char p='0',ce='0',li='0';

    for(int i=0;i<4;i++){
        char a[100]={0};
        cin>>a;
        if((i==0||i==2))
           {
                if(a=="01" || a=="16"){y++;}
                else {e++;}
           }
        else{
            if(i==1) {q.push_back(a[2]);}


            char c[2]={0};
            c[0]=a[0];
            c[1]=a[1];
            if(yan(c[0],c[1])==1){
                p='1';
                if(!q.empty())
                {
                    if(lin(a[2],q[0])==1) {ce='1';}
                    if(lin(a[2],q[0])==2) {ce='1';
                    li='1';}
                }
            }
            else {b.push_back(c);}
        }


    }
    if(y>1||e>1) {cout<<'1';}

    cout<<p<<ce<<li;


    fclose(stdin);
    fclose(stdout);

    return 0;
}
