#include<bits/stdc++.h>
using namespace std;
int a,b;
string a1,b1;
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);

cin>>a>>a1;
cin>>b>>b1;
if(a==b){
cout<<1;
}
else
cout<<0;
int n=(a1[0]-32)*10+(a1[1]-32);
int m=(b1[0]-32)*10+(b1[1]-32);
if(n==m){
    cout<<1;
}
else
cout<<0;
char x=a1[2];
char y=b1[2];
if(x=='D'&&y=='F'||x=='F'&&y=='D'){
    cout<<11;
}
else if((x=='A'||x=='B'||x=='C')&&(y=='A'||y=='B'||y=='C'))
{
    cout<<1;
    if(x=='A'&&y=='C'||y=='A'&&x=='C'){
        cout<<0;
    }
    else{
        cout<<1;
    }
}
else
    cout<<0;

return 0;
}
