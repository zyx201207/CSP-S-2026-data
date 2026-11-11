#include <bits/stdc++.h>
using namespace std;
long long a[1]
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n;
    cin>>n;
    string s,c;
     while(n--){
        cin>>a>>s;
        for(int i=1;i<=a;i++){
            c+=s;
        }
    }
    cout<<s;
    return 0;

}
