#include<bits/stdc++.h>
using namespace std;
long long int n,t,sum,j;
string s;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t>>c;
        for(long long int i=0;i<t;i++){
            s+=c;
        }
    }
    j=s.size();
    for(long long int i=0;i<j/2;i++){
        if(s[i]!=s[j-1-i])sum++;
    }
    cout<<sum;
    return 0;
}
