#include<bits/stdc++.h>
using namespace std;
    int sl[2500001];
    char zf[20005];
    //char zf[1000001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m,num=0,o,k,d,c=0;
    cin>>n;
    char a;
    for(int i=1;i<=n;i++){
        cin>>m;
        num+=m;
        cin>>a;
        m=a-'a';
        for(int i=1;i<=m;i++){
            sl[i]=m;
        }
    }
    if(num%2==0){
        o=num/2;
        k=o;
        d=o+1;
    }else{
        o=num/2+1;
        k=o-1;
        d=o+1;
    }
    for(int i=1;i<=o;i++){
        if(sl[k]!=sl[d]){
            c++;
        }
        k--;
        d++;
    }
    for(int i=1;i<=o;i++){
        //cout<<sl[i]<<" ";
    }
    cout<<c;
    return 0;
}
