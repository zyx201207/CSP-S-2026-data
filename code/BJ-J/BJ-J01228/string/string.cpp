#include<bits/stdc++.h>
using namespace std;
string a;
string b;
long long sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        long long x;
        cin>>x;
        char c;
        cin>>c;
        while(x--) a+=c;
    }
    for(long long i=a.length()-1;i>=0;i--){
        b+=a[i];
    }
    for(long long i=0;i<a.length();i++){
        if(b[i]!=a[i]) sum+=1;
    }
    sum/=2;
    cout<<sum;
    return 0;
}
