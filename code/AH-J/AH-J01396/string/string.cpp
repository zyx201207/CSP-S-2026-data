#include<bits/stdc++.h>
using namespace std;
stack<char> a;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    vector<long long> x(n,0);
    vector<char> c(n,0);
    for(long long i=0;i<n;i++){
        cin>>x[i]>>c[i];
    }
    long long i=0,j=x.size()-1,cnt=0;
    while(i<j){
        if(c[i]!=c[j])cnt+=min(x[i],x[j]);
        if(x[i]>x[j])x[i]-=x[j],j--;
        else if(x[i]<x[j])x[j]-=x[i],i++;
        else if(x[i]==x[j])i++,j--;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
}
