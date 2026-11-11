#include<bits/stdc++.h>
using namespace std;
int main(){
    ifstream fi("string.in");
    ofstream fo("string.out");
    string s1="";
    int n,x[55555],X=0,mi=111111111;
    char a[55555];
    fi>>n;
    for(int i=0;i<n;i++){
        fi>>x[i]>>a[i];
        mi=min(x[i],mi);
    }
    for(int i=0;i<n;i++){
        x[i]-=mi;
        X+=x[i];
        for(int j=0;j<x[i];j++){
            s1+=a[i];
        }
    }
    int ans=0;
    for(int i=0,j=X-1;i<X,j>=0;i++,j--){
        if(s1[i]!=s1[j]){
            ans++;
        }
    }
    fo<<ans*mi<<endl;
    return 0;
}
