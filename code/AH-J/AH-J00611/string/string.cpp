#include<bits/stdc++.h>
using namespace std;
long long int mid,n,x,p,sum;
string s;
char c;
int main(){
    cin>>n;
    p=0;
    for(long long int i=1;i<=n;i++){
        cin>>x;
        cin>>c;
        for(int j=1;j<=x;j++){
            s+=c;
        }
    }
    p=s.size()-1;
    for(long long int i=0;;i++){
        if(i>=p) break;
        if(s[i]!=s[p]) sum++;
        p--;
    }
    cout<<sum;
    return 0;
}
