#include<bits/stdc++.h>
using namespace std;
string a,b;
int c1,c3;
int an1,an2,an3,an4;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>c1>>a>>c3>>b;
    if(c1==c3){
        an1=1;
        if(a[0]==b[0]&&a[1]==b[1]){
            an2=1;
            char x=a[2],y=b[2];
            if((x=='A'||x=='B'||x=='C')&&(y=='A'||y=='B'||y=='C')){
                an3=1;
                if((x=='A'&&y=='B')||(x=='B'&&y=='A')||(x=='C'&&y=='B')||(x=='B'&&y=='C'))an4=1;
                else an4=0;
            }
            else{
                if((x=='D'||x=='E')&&(y=='D'||y=='E'))an3=1,an4=1;
                else an3=0,an4=0;
            }
        }
        else{
            an2=0,an3=0,an4=0;
        }
    }
    else{
        an1=0,an2=0,an3=0,an4=0;    
    }
	cout<<an1<<an2<<an3<<an4;

}
