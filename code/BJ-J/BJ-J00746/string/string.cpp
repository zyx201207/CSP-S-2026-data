#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,n1,n2;
int cnt=0;
const int N=2e5+7;
int l1[N];
int l2[N];
int suml;
int c1[N];
int c2[N];
int s[100000007];

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char y;
        cin>>x>>y;
        l1[i]=x;
        suml+=x;
        c1[i]=y-'a';
    }
    for(int i=1;i<=n;i++){
        l2[i]=l1[n-i+1];
        c2[i]=c1[n-i+1];
    }
    int lij=0,ri=l1[1],rj=l2[1];
    for(int i=1,j=1;lij<suml/2;){
        int dif=(c1[i]!=c2[j]);
        cnt+=dif*(min(min(ri,rj),suml/2)-lij);
        lij=min(ri,rj);
        if(lij>=suml/2)break;
        if(ri==lij){
            i++;
            ri+=l1[i];
        }
        if(rj==lij){
            j++;
            rj+=l2[j];
        }
    }
    cout<<cnt<<endl;
    return 0;
}
