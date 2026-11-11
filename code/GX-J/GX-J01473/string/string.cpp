#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    long long n,m,sum=0;
    char a;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>m>>a;
        for(long long i=1;i<=m;i++){
            s+=a;
        }
    }
    long l=s.size();
    long i=0,j=l-1;
    for(long q=0;q<=j;q++){
       if(s[i]!=s[j]){
            sum++;
        }
        i++;j--;
    }
    cout<<sum;
    return 0;
}
