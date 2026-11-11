//GZ-J0042 威宁彝族回族苗族自治县民族初级中学 谢一尘
#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    int a[1000000];
    int c[1000000];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
    }

    if(n<=2){
        cout<<0;
    }

    return 0;
}
