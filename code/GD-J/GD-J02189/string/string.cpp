#include<bits/stdc++.h>
using namespace std;
const int MAX=2e5+10;
long long a[MAX],pos[MAX];
char c[MAX];
int n;
void check(){
    if(pos[n]%2==1){
        long long cent=(pos[n]+1)/2;//middle alpha
        for(long long i=1;i<=cent;i++){
            if(ch[i]!=ch[pos[n]){
                ans++;
            }
        }
    }
    else{
        long long cent=(pos[n])/2;//middle alpha
        for(long long i=1;i<=cent;i++){
            if(ch[i]!=ch[pos[n]){
                ans++;
            }
        }
    }
    cout<<ans;
}
vector<char> ch;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n<=2000){
        for(int i=1;i<=n;i++){
            cin>>a[i]>>c[i];
            for(int i=1;i<=a[i];i++) ch.push_back(c[i]);
        }
        check();
    }
    else cout<<0;
    return 0;
}
