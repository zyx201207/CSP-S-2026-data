#include<bits/stdc++.h>
using namespace std;
const int MAX=5e5+10;
long long n,a,l=1,z=0,d=0,j;
char k,b[MAX];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        cin>>k;
        l+=a;
        z+=a;
        for(int i=l-a;i<l;i++){
            b[i]=k;
        }
    }
    if(z%2==0){
        j=z/2;
    }else{
        j=z/2+1;
    }
    for(int i=z;i>j;i--){
        if(b[i]!=b[z-i+1]) d++;
    }
    cout<<d;
    return 0;
}
