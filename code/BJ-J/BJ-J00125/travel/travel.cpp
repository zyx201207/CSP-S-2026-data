#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int lift1,lift2,seat1,seat2,se1,se2;
bool xiang=0,pai=0,guodao=0,lin=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    lift1=(c1[0]-'0')*10+(c1[1]-'0');
    lift2=(c2[0]-'0')*10+(c2[1]-'0');
    seat1=(s1[0]-'0')*10+(s1[1]-'0');
    seat2=(s2[0]-'0')*10+(s2[1]-'0');
    if(s1[2]=='F')se1=5;
    else se1=s1[2]-'A'+1;
    if(s2[2]=='F')se2=5;
    else se2=s2[2]-'A'+1;
    //printf("%i %i %i %i %i %i\n",lift1,lift2,seat1,seat2,se1,se2);
    if(lift1==lift2){
        xiang=1;
        if(seat1==seat2){
            pai=1;
            if((se1<=3&&se2>=4)||(se1>=4&&se1<=3)){
                guodao=0;
                lin=0;
            }else{
                guodao=1;
                if(se1+1==se2||se2+1==se1){
                    lin=1;
                }else lin=0;
            }
        }else{
            pai=0;
            guodao=0;
            lin=0;
        }
    }else{
        xiang=0;
        pai=0;
        guodao=0;
        lin=0;
    }cout<<xiang<<pai<<guodao<<lin;
    return 0;
}

