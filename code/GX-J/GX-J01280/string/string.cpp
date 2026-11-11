#include<iostream>
using namespace std;
int main(){
    freopen("string","r",stdin);
    freopen("string","w",stdout);
    int n,m;
    char s;
    long long S=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m>>s;
        while(m){
            S+=s;
        }
    }
    return 0;
}
