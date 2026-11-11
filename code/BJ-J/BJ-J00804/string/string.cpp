#include<iostream>
#include<string>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a[200005];
    long long n;
    long long m;
    char b;
    string s;
    cin>>n;
    int c=0;
    for(int i=1;i<=n;i++){
        cin>>m;
        cin>>b;
        for(int j=1;j<=m;j++){
            s[c]=b;
            c++;
        }
    }
    int e=n/2;
    long long d=0;
    for(int i=0;i<e;i++){
        if(s[i]!=s[e-i]){
            d++;
        }
    }
    cout<<d;
    return 0;
}
