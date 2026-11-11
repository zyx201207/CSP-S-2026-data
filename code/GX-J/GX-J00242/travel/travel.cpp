#include <bits/stdc++.h>
using namespace std;

int main (){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);

string c1,s1,c2,s2;
cin >> c1 >>s1 >>c2>>s2;
int n=0;
bool f=0;
for (int i=0;i<2;i++){
    if(c1[i]==c2[i]){
        n++;
    }
}
if(n==2){
    cout << 1;
}
else{
    cout <<0;
    f=1;
}
n=0;
for (int i=0;i<2;i++){
    if(s1[i]==s2[i]){
        n++;
    }
}
if(n==2&&f==0){
    cout << 1;
}
else{
    cout <<0;
    f=1;
}
if(s1[2]-'A'<=3&&s2[2]-'A'>3&&f==1){
    cout <<0;
    f=1;
}
else if(s2[2]-'A'<=3&&s1[2]-'A'>3&&f==1){
    cout << 0;
    f=1;
}
else{
    cout << 1;
}
if((s1[2]-'A')-(s2[2]-'A')>=2&&f==1){
    cout <<0;
}
else if((s1[2]-'A')-(s2[2]-'A')>=2&&f==1){
    cout << 0;
}
else{
    cout << 1;
}

return 0;
}
