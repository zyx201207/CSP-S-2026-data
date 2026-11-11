#include<bits/stdc++.h>
using namespace std;
long long c1,c2,a1,a2;
string s1,s2;
char b1,b2;
bool flag=1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1 == c2){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
    int si1 = s1.size(),si2 = s2.size();
    for(int i = 0;i < si1;i++){
        if(s1[i] >= '0' &&s1[i] <= '9'){
            a1 = a1*10 +(s1[i]-'0');
        }else{
            b1 = s1[i];
        }
    }
    for(int i = 0;i < si2;i++){
        if(s2[i] >= '0' &&s2[i] <= '9'){
            a2 = a2*10 +(s2[i]-'0');
        }else{
            b2 = s2[i];
        }
    }
    if(a1 == a2){
        cout<<"1";
    }else{
		cout<<"000";
        return 0;
    }
    if(((b1 >= 'A' &&b1 <= 'C') &&(b2 >= 'A' &&b2 <= 'C')) || ((b1 == 'D' &&b2 == 'F') &&(b2 == 'D' &&b1 == 'F'))){
        cout<<"1";
    }else{
        cout<<"00";
        return 0;
    }
    int tmp1=b1-'A',tmp2 = b2-'A';
    if((b1 == 'C' && b2 == 'D') || (b2 == 'C' && b1 == 'D'))
		flag = 0;
    if(abs(tmp1 - tmp2) == 1 && flag){
        cout<<"1";
    }else{
        cout<<"0";
    }
    return 0;
}
