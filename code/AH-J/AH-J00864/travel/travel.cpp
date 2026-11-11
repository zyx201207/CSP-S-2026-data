#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
bool a[4];
ll seat1,seat2,num1,num2;
char ch1,ch2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    seat1=(c1[1]-'0')*10+(c1[0]-'0');
    seat2=(c2[1]-'0')*10+(c2[0]-'0');
    num1=(s1[1]-'0')*10+(s1[0]-'0');
    num2=(s2[1]-'0')*10+(s2[0]-'0');
    ch1=s1[2],ch2=s2[2];
    if(seat1==seat2){
        a[0]=true;
        if(num1==num2){
            a[1]=true;
            if((ch1=='A'||ch1=='B'||ch1=='C')&&(ch2=='A'||ch2=='B'||ch2=='C')){
                a[2]=true;
                if(abs((ll)ch1-(ll)ch2)==1)a[3]=true;
            }else if((ch1=='D'||ch1=='F')&&(ch2=='D'||ch2=='F')){
                a[2]=true,a[3]=true;
            }
        }
    }
    for(int i=0;i<4;i++)cout<<a[i];
    return 0;
}
