#include <bits/stdc++.h>
using namespace std;

int b[100000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int a,d,as,ans,bb;
    cin >> a;
    for(int i=0;i<a;i++){
        cin >> d>> as;
        bb+=d;
        for(int f=0;f<=d;f++){
            b[f]=as;
        }
    }
    for(int i=0;i<=bb;i++){
        if(b[i]!=b[bb-i]){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
