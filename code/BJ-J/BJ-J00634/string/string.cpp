#include<bits/stdc++.h>
using namespace std;
long long n,l;
string s;
long long change(string ss){
    long long sum=0;
    for(long long i=0;i<ss.size()/2;i++){
        if(ss[i]!=ss[ss.size()-i-1])
            sum++;
    }
    return sum;
}
int main(){
    freopen(string.in,"r",stdin);
    freopen(string.out,"w",stdout);
    cin>>n;
    while(n--){
        string c;
        int a;
        cin>>a>>c;
        while(a--)
            s+=c;
    }
    cout<<change(s);
    return 0;
}
