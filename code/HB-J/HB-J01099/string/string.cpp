#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long ms[n+5];
    string mc[n+5];
    int s=0;
    for(int i=1;i<=n;i++){
        cin>>ms[i];
        cin>>mc[i];
        s=s+ms[i];
    }
    char l[s+2];
    int kong=1;
    for(int i=1;i<=n;s++){
        for(int j=1;j<=ms[i];j++){
            l[kong]=mc[i];
            kong++;
        }
    }
    int cuo=0;
    for(int i=1;i<=n;i++){
        if(l[i]!=l[s+1-i])[
            cuo++;
        ]
    }
    cout<<cuo;
    return 0;
}
