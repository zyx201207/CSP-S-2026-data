#include<bits/stdc++.h>
using namespace std;


int main(){
    //freopen("crystal.in","r",stdin);
  //  freopen("crystal.out","w",stdout);

    long long a[10000]={0};
    int n,m,s;
    cin>>m>>n;

    set<string> power;

    for(int i=1;i<=n;i++){
        string s;
        power.insert(s);
        a[i]=a[i]+m;
        s=a[i]/m;
    }
    cout<<s<<endl;
    return 0;
}
