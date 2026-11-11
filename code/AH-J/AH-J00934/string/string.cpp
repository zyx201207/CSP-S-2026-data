#include<bits/stdc++.h>
using namespace std;
long long a,b;
string u;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>a;
    long long cnt=0;
    for(int i=1;i<=a;i++){
        b=0;
        char k;
        cin>>b>>k;
        long long o=cnt+b;
        for(int j=cnt;j<o;j++){
            u=u+k;
        }
        cnt+=b;
    }
    double l=u.length()/2.00;
    long long g=u.length()/2;
    if(l!=g){
        g+=1;
    }
    long long ff=u.length();
    long long sum=0;
    for(int i=0;i<g;i++){
        if(u[i]!=u[ff-i-1]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
