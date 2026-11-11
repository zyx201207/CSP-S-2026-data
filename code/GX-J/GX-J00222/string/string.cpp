#include <bits/stdc++.h>
using namespace std;

int cnt=0;
long long n;
string as[20005];
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    int s;
    cin>>n;
    while(n--){
        cin>>s;
        string ch[20005];
        for(int i=0;i<=s;i++){
            cin>>ch[i];
            as[i]+=ch[i];
        }
        for(int i=0;i<=s;i++){
            cout<<as[i];

        }


    }
    return 0;
}
