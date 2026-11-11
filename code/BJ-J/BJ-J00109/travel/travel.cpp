#include<bits/stdc++.h>
using namespace std;
int c1,c3;
string c2,c4;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>c1>>c2>>c3>>c4;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>c3>>c4;
    if(c1==c3){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
    if(c2[0]==0){
        c2.erase(0,1);
    }
    if(c4[0]==0){
        c4.erase(0,1);
    }
    if(c2==c4){
        cout<<"1";
    }else{
        cout<<"000";
        return 0;
    }
    string s3,s4;
    int len1,len2;
    len1=c2.size();
    len2=c4.size();
    s3=c2[len1];
    s4=c4[len2];
    if(((s3=="A"||s3=="B"||s3=="C")&&(s4=="A"||s4=="B"||s4=="C"))||((s3=="D"||s3=="F")&&(s4=="D"||s4=="F"))){
        cout<<"1";
    }else{
        cout<<"00";
        return 0;
    }
    if((s3=="A"&&s4=="B")||(s3=="B"&&s4=="A")||(s3=="B"&&s4=="C")||(s3=="C"&&s4=="B")||(s3=="D"&&s4=="F")||(s3=="F"&&s4=="D")){
        cout<<"1";
    }else{
        cout<<"0";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
