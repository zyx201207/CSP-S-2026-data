#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a,sum=0;
    string c,s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>c;
        while(a--){
            s+=c;
        }
    }
    long long l=0,r=s.size()-1;
    while(l<=r){
        if(s[l]==s[r]){
            l++;
            r--;
        }
        else{
            sum++;
            l++;
            r--;
        }
    }
    cout<<sum;
    return 0;
}
