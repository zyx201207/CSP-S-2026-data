#include <bits/stdc++.h>
using namespace std;
string x(long long p){
    string q;
    while(p>0){
        q+=(p%2+'0');
        p/=2;
    }
    reverse(q.begin(),q.end());
    return q;
}
int r(string y){
    for(int i = 0;i<y.size();i++)
}
string a;
int n,len;
string o(string a,long long b,long long m){
    if(a.size()==m){
        return a;
    }
    string c;
    int j = 0;
    for(int i = 0;i<len;i++){
        if(a[i][b]==1){
            c[j] = a[i];
            j++;
        }

    }
    if(c.size()<m){
        return o(a,b+1,m);
    }
    else{
        return o(c,b+1,m)
    }
}
int main(){
    cin>>n;
    for(int i = 0;i<n;i++){
        long long v;
        cin>>v;
        a[i] = x(v);
        len = max(len,x(v));
    }
    string k = o(a,0,m);
    int g[20005];
    for(int i = 0;i<a.size();i++){

    }
    return 0;
}
