#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int zxc=0;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
    cout<<"1";
    zxc++;
    }else if(c1!=c2){
    cout<<"0";
    }
    string a,s;
    char d,f;
    for(int i=0;i<3;i++){
        if(s1[i]>='0'&&s1[i]>='9'){
            a[i]=s1[i];
        }
        if(s2[i]>='0'&&s2[i]>='9'){
            s[i]=s2[i];
        }
    }
    for(int i=0;i<3;i++){
        if(s1[i]>='A'&&s1[i]>='Z'){
            d=s1[i];
        }
        if(s2[i]>='A'&&s2[i]>='Z'){
            f=s2[i];
        }
    }
    if(a==s){
    cout<<"1";
    zxc++;
    }else if(a!=s){
    cout<<"0";

    }
    if(a==s&&d<='C'&&f<='C'){
    cout<<"1";
    zxc++;
    }else if(a!=s||d>='C'||f>='C'){
    cout<<"0";

    }
    if(zxc>=3&&d-f==1||f-d==1){
    cout<<"1";
    }else if(zxc<3||d-f!=1||f-d!=1){
    cout<<"0";
    }
return 0;
}
