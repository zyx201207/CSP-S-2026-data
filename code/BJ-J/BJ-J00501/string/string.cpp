#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+50;
int n,a,t;
char b;
string s;
bool f(){
    for(int i=0,j=s.size()-1;i<=j;i++,j--){
        if(s[i]!=s[j]){
            return 0;
        }
 //   cout<<s[i]<<" "<<s[j]<<endl;
    }
    return 1;
}

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        for(int j=0;j<a;j++){
            s+=b;
        }
    }

    if(f()==1){
        cout<<t;
        return 0;
    }
    while(f()==0){
        t++;
        for(int i=0,j=s.size()-1;i<=j;i++,j--){
            if(s[i]!=s[j]){
                s[j]=s[i];
                break;
            }
        }
    }
    cout<<t;
    return 0;
}
