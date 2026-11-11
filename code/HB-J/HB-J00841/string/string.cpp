#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long l=0;
    int a[100111];
    char c[101101];
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    string s="";
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i];j++){
            s+=c[i];
        }
    }
    long long r=s.size()-1;
    long long sum=0;
    while(l!=r){
        if(l>=r){
            break;
            }
        if(s[l]!=s[r]){
            sum++;
            }
        r--;
        l++;
    }
    cout<<sum;
    return 0;

}
