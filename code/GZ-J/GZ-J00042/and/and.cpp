//GZ-J0042 威宁彝族回族苗族自治县民族初级中学 谢一尘
#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n,s=0;
    int a[100005];
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];

    if(m==1){
        s=max(a[i],a[i+1]);

        }
    }
    cout<<s;
    return 0;
}
