#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,b;
    char s;
    cin>>n>>a;
    cin.getline(s,1000);
    for(int i=0;i<strlen(s);i++){
        if(a==b){
            s++;
        }
        a++;
        b=b%10+2;
    }

    return 0;
}
