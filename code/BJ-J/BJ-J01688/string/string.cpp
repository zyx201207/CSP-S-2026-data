#include<bits/stdc++.h>
using namespace std;
unsigned long long n,s=0,k=0;
vector<char> y;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        unsigned long long c;
        cin>>c;
        char q;
        cin>>q;
        unsigned long long o=c;
        s+=o;
        while(c){
           y.push_back(q);
           c--;
        }
    }
    unsigned long long p=s/2,i=0;
    while(p){
        if(y[i]!=y[s-i-1])k++;
        i++;
        p--;
    }
    cout<<k;
    return 0;
}
