#include<bits/stdc++.h>
using namespace std;
long long n,s;
char ch;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    string f;
    for(int i=1;i<=n;i++){
        cin>>s>>ch;
        for(int j=1;j<=s;j++){
            f=f+ch;
        }
    }
    long long sum=0;
    for(int i=0;i<=f.size()/2-1;i++){
        if(f[i]!=f[f.size()-1-i]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
