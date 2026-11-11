#include<bits/stdc++.h>
using namespace std;
long long q,n,p[10000100],a,k=1,a1[100000010];
int flag;
string s;
int main(){
    
    freopen("string","r","in");
    freopen("string","w","out");
    cin>>n;
    q=n;
    while(n--){
        cin>>a>>s;
        a1[n]=a;
        for(int i=k;i<=k+a;i++){
            p[i]=s[0];
        }
        k+=a;
    }int flag1=1;
    for(int i=2;i<=q;i++){
        if(a1[i]!=a1[i-1]){
            flag1=0;
            break;
        }
    }
    if(flag1){
        for(int i=1;i<=q;i++){
            if(a1[i]!=a1[q+1-i]){
                flag++;
                a1[q+1-i]=a1[i];
            }
        }
        cout<<flag*s[0]<<endl;
        return 0;
    }
    for(int i=1;i<=k;i++){
        if(p[i]!=p[k+1-i]){
            flag++;
            p[k+1-i]=p[i];
        }
    }
    cout<<flag<<endl;
    return 0;
}
