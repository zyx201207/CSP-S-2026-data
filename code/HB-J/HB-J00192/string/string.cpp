#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    while(n--){
        int x;char c;
        scanf("%d",&x);
        cin>>c;
        while(x--){
            s+=c;
        }
    }
    int lens=s.size();
    for(int i=0;i<lens/2;i++){
        if(s[i]!=s[lens-1-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
