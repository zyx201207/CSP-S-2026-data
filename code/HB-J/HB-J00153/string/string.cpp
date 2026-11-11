#include <bits/stdc++.h>
using namespace std;

int n,ans=0;
string s;


int main(){


    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);


    cin>>n;

    for(int i=1;i<=n;i++){
        int a;
        string c1,c2;
        cin>>a>>c1;
        c2='#'+c1;
        if(a==1){
            s=s+c2;
            continue;
        }
        if(a%2==0){
            for(int j=a;j>=2;j=j/2){
                c2=c2+c2;
            }
        }
        else{
            a--;
            for(int j=a;j>=2;j=j/2){
                c2=c2+c2;
            }
            c2=c2+'#'+c1;
        }
        s=s+c2;
    }

    int len=s.size();

    int l=len/2,r=len/2;
    if(s[l]==s[r]&&s[l]=='#'){
        l--;
        r++;
    }

    while(l>=1&&r<=len){
        if(s[r]!=s[l]){
            ans++;
        }
        l=l-2;
        r=r+2;
    }

    cout<<ans;

    return 0;
}
