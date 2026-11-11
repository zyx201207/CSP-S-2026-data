#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,c2,s1,s2;
ll a1,a2,b1,b2;
char d1,d2;
bool x[5]={};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    a1=(c1[0]-'0')*10+(c1[1]-'0');
    a2=(c2[0]-'0')*10+(c2[1]-'0');
    if(a1!=a2){
        x[0]=x[1]=x[2]=x[3]=0;
    }else{
        x[0]=1;
        b1=(s1[0]-'0')*10+(s1[1]-'0');
        b2=(s2[0]-'0')*10+(s2[1]-'0');
        if(b1!=b2){
            x[1]=x[2]=x[3]=0;
        }else{
            x[1]=1;
            d1=s1[2],d2=s2[2];
            if(d1=='A'||d1=='B'||d1=='C'){
                if(d2=='A'||d2=='B'||d2=='C'){
                    x[2]=1;
                    if(x[1]&&abs(d1-d2)==1)x[3]=1;
                }
            }else{
                if(d2=='D'||d2=='F'){
                    x[2]=1;
                    if(x[1])x[3]=1;
                }
            }
        }

    }
    for(ll i=0;i<4;i++)cout<<x[i];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
