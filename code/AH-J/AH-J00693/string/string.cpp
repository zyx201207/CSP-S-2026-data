#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a,cnt=0,j;
    string c,s;
    cin>>n;
    while(n--){
        cin>>a>>c;
        while(a--)s+=c;
    }
    j=s.size()-1;
    for(long long i=0;i<j;i++){
        if(s[i]!=s[j])cnt++;
        j--;
    }
    cout<<cnt;
    return 0;
}
