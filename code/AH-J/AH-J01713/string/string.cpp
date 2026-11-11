#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[500005];

char b[500005];
long long ans=0;
string ss;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        ans+=a[i];
    }
    long long k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i];j++){
            ss[k]=b[i];
            k++;
        }
    }
    long long sum=0;
    for(int i=0;i<ans/2;i++){
        if(ss[i]!=ss[ans-1-i]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}

