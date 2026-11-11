
#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);

for(int i=0;i<=4;i++){
    cin>>s;
    if(s[i]==s[i+2]){
        cout<<0;
    }
    else{
        cout<<1;
    }
}
for(int i=0;i<=4;i++){
    cin>>s;
    if((s[i]<3&&s[i+1]<3)||((s[i]==4)&&(s[i+1]==5))){
        cout<<0;
    }
    else{
        cout<<1;
    }
}
return 0;
}

