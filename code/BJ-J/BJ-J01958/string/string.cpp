#include<iostream>
#include<string>
using namespace std;

long long n,sum;
string s,f;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        long long a;
        string a2;
        cin>>a>>a2;
        for(long long j=1;j<=a;j++){
            s+=a2;
        }
    }
    f=s;
    f.reverse(f.begin(),f.end());
    for(long long i=0;i<s.size()/2;i++){
        if(s[i]!=f[i]){
            f[i]==s[i];
            sum++;
        }
        if(s==f){
            break;
        }
    }
    cout>>sum;

    return 0;
}