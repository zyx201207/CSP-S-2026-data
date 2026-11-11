#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,b,c;
    cin >> a >> b;
    int l[a],l2[a],m=0;
    for (int j = 1;j<=a;j++){
        l2[j-1]=0;
    }
    for (int i = 1;i <= a;i++){
        cin >> l[i-1];
    }
    if (b == 1){
        for (int k = 1;k<=a;k++){
            if (l[k-1]>m){
                m=l[k-1];
            }
        }
    }


    cout << m;
    return 0;
}
