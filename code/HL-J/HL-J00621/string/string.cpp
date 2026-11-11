#include<bits/stdc++.h>
using namespace std;
long long a[100001];
string b[100001];
int main(){
    int n;
    cin>>n;
    string m;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        for(int j=1;j<=a[i];j++){
            m+=b[i];
        }
    }
    long long sum=0
    for(long long i=0;i<m.size()/2;i++){
        long long j=m.size();
        if(m[i]!=m[j]){
            sum++;
        }
        j--;
    }
    cout<<sum;
    return 0;
}
