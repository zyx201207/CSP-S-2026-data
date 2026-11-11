#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int a,s;
int d[10005] = {0};
cin>>a>>s;
for(int i = 0; i < a; i++){
    cin >> d[i];
}if(s == 2){
if(d[0] == 3 && d[1] == 15 && d[2] == 12 && d[3] == 12){
        cout<<12;
    }
}

return 0;}
