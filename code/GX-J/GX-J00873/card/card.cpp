#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
long long bookall[500005];
long long booktmp[500005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ull n,m;
    vector<ull> T;
    cin>>n>>m;
    for(ull i=0;i<n;i++){
        ull a;
        cin>>a;
        T.push_back(a);
    }
    reverse(T.begin(),T.end());

//    for(const ull& b : T){
//    cout<<b<<"\n";}
//    cout<<"ok!\n";
    for(ull i=0;i<n;i++){
        //1-st
//        cout<<"new!\n";
        for(long long j=i;j>=0;j--){
//            cout<<i<<" "<<j<<" "<<T[j]<<" "<<!(booktmp[T[j]]>=1)<<"\n";
//            cout<<"-"<<booktmp[T[j]]<<" "<<bookall[T[j]]<<"\n";
            if(!(booktmp[T[j]]>=1)){
                booktmp[T[j]]++;
            }else{
//                cout<<"---"<<"\n";
                for(long long f=j+1;T[f]!=T[j];f--){
//                    cout<<"---"<<j<<" "<<f<<"\n";
                    booktmp[T[f]]--;
                }
            }
        }
        for(long long j=0;j<=m;j++){
            bookall[j]+=booktmp[j];
            booktmp[j]=0;
        }
    }

    for(ull i=1;i<=m;i++){
        cout<<bookall[T[i]]<<" ";
    }
    return 0;
}
