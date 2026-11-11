#include<bits/stdc++.h>
using namespace std;
long long  n;
string s;
long long sum;
bool h(){
    bool flag=0;
    long long  l=s.size()-1,j=0;
    for(int i=(l+1)/2;i>=0;i--){
        if(s[i]!=s[j]){
            flag=1;sum++;
        }
        j++;
    }
    return !flag;
}
//6 1000000000 a 1000000000 a 1000000000 a 1000000000 b 1000000000 b 1000000000 b
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        long long  a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    bool  ans=h();
    if(ans==1){
        cout<<0;
    }else cout<<sum;

    return 0;
}

