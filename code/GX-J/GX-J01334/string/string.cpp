#include<bits/stdc++.h>
using namespace std;
int n=0;
int a=0;
int L=0;
int cor=0;
string S,c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>c;
        string x;
        x=c;
        for(int j=0;j<a-1;j++){
            c+=x;
        }
        S=S+c;
        L+=a;
    }
    for(int i=0;i<L;i++){
            int j=L-1-i;
    if(i>=j){
        break;
    }
            if(S[i]==S[j]){
                continue;
            }else{
                cor+=1;
            }
    }
    cout<<cor;
    return 0;
}
