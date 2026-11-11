#include<bits/stdc++.h>
using namespace std;
struct p{
    int g;
    char z;
}a[200050];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long int n,l=0,sum=0;
    string s;
    s +='0';
    cin>>n;
    for(long long int i=1;i<=n;i++){
        cin>>a[i].g>>a[i].z;
        l+=a[i].g;
        for(long long int j=1;j<=a[i].g;j++){
                s +=a[i].z;
        }
    }
    for(long long int i=1;2*i<=l;i++){
        if(s[i]!=s[l+1-i] && l-i<=s.size()){
            sum++;
        }
    }
    cout<<sum<<endl;
    return 0;
}
