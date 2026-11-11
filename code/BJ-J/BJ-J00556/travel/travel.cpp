#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,c3,c4;
    cin>>c1>>c2>>c3>>c4;
    string d = "",f = "";
    for(int i = 0; i <= 1; i++ ){
        d += c2[i];
        f += c4[i];
    }
    if(c1 == c3){
        cout<<"1";
    }else{
        cout<<"0";
    }
    if(c1 == c3 && d == f){
        cout<<"1";

    }else{
        cout<<"0";
    }
    if(c1 == c3 && d == f && (((c2[2] == 'A' || c2[2] == 'B' || c2[2] == 'C') && (c4[2] == 'A' || c4[2] == 'B' || c4[2] == 'C')) || ((c2[2] == 'D' || c2[2] == 'F') && (c4[2] == 'D'|| c4[2] == 'F')))){
        cout<<"1";
    }else{
        cout<<"0";
    }
    if(c1 == c3 && d == f && (((c2[2] == 'A' || c2[2] == 'B' || c2[2] == 'C') && (c4[2] == 'A' || c4[2] == 'B' || c4[2] == 'C')) || ((c2[2] == 'D' || c2[2] == 'F') && (c4[2] == 'D'|| c4[2] == 'F'))) && ((c2[2] - c4[2] == 1 || c4[2] - c2[2] == 1) && (c2[2] != 'C' || c4[2] != 'D'))){
        cout<<"1";
    }else{
        cout<<"0";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
