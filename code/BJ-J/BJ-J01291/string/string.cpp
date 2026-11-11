#include<bits/stdc++.h>
using namespace std;
int n,fst=0,lst;
long long b[200009];
char c[200009];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    lst=n-1;
    for(int i=0;i<n;i++){
        cin>>b[i]>>c[i];
    }
    long long ls=0,ans=0;
    while(1){
        if(fst>=lst){

            break;
        }
        if(c[fst]==c[lst]){
            if(b[fst]>b[lst]){
                b[fst]=b[fst]-b[lst];
                b[lst]=0;
                lst--;

            }else{
                b[lst]=b[lst]-b[fst];
                b[fst]=0;
                fst++;
            }
        }else{
            if(b[fst]>b[lst]){
                ans=ans+b[lst];
                b[fst]=b[fst]-b[lst];
                b[lst]=0;
                lst--;

            }else{
                ans=ans+b[fst];
                b[lst]=b[lst]-b[fst];
                b[fst]=0;
                fst++;
            }
        }
    }
    cout<<ans;
    return 0;
}
