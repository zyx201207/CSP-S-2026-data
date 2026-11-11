#include<iostream>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int t,k=0;
    string s;
    cin>>t;
    while(t--){
        int n;
        char x;
        cin>>n>>x;
        for(int i=k;i<k+n;i++) s[i]=x;
        k+=n;
    }
    int sum=0;
    for(int i=0;i<(k+1)/2;i++){
        if(s[i]!=s[k-1-i]){
            s[i]=s[k-1-i];
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
