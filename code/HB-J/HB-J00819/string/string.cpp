#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    string s="";
    int n;
    cin>>n;
    long long a[100005];
    char c[100005];
    long long sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        for(int j=0;j<a[i];j++){
            s=s+c[i];
        }
    }
    long long k=s.size();
    for(long long i=0;i<k/2;i++){
        if(s[i]!=s[k-i-1])sum++;
    }
    cout<<sum;
}

