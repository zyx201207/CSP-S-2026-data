#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long ansl[1000000];
long long cord[1000000];
long long lst[1000000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    //for(int i=1;i<=n;i++){
    //    ansl[i]=n;
    //    ansl[i]-=i;
    //}
    for(int i=1;i<=n;i++){
        cin>>lst[i];
        ansl[lst[i]]+=i;
        if(cord[lst[i]]!=0){
            for(int j=cord[lst[i]]+1;j<=i;j++){
                if(ansl[lst[j]]>0){ansl[lst[j]]--;}//front--
            }
        }
        cord[lst[i]]=i;
    }
    for(int i=1;i<=m;i++){
        cout<<ansl[i]<<' ';
    }
    return 0;
}
