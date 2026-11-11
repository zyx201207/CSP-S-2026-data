#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    int n,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char b;
        cin>>a>>b;
        for(int j=1;j<=a;j++){
            s+=b;
        }
    }
    int i=0,j=s.size()-1;
    while(i<=j){
        if(s[i]!=s[j]){
            sum+=1;
        }
        i++;
        j--;
    }
    cout<<sum;
    return 0;
}
