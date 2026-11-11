#include<bits/stdc++.h>
#include<string>>
using namespace std;

int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string z;
    z="";
    string c1,s1,c2,s2;
    cin>>c1;
    cin>>s1;
    cin>>c2;
    cin>>s2;

    int q=z.size();
    int shuru,geshu;
    int t;

    if(c1==c2){
        cout << 1;
    }else{
        cout << 0;
    }
    if(c1[0]==c2[0]&&c1[1]==c2[1]){
        cout << 1;
    }
    string c;
    c=s1[2];
    string v;
    v=s2[2];
    if((c=="A"||c=="B"||c=="C")&&((v=="A"||v=="B"||v=="C")||(c=="D"||c=="F")&&(v=="D"||v=="F"))){
            cout << 1;
    }else{
        cout << 0;
        t=0;
    }
    if(t!=0){
        if((c=="A"||c=="B"&&v=="A"||v=="B")||((c=="B"||c=="C"&&v=="B"||v=="C"))){
            cout << 1;
        }else{
            cout << 0;
        }
    }else{
        cout << 0;
    }


    return 0;
}
