#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int MAXN=2*1e5+5;
struct dt{
    int bg,ed;
    int l;
    char c;
}s[MAXN];
int n;
int len=0;

int rev(int i){
    return len-i+1;
}

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    s[0].bg=0;
    s[0].ed=0;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        len+=a;
        s[i].bg=s[i-1].ed+1;
        s[i].ed=len;
        s[i].l=a;
        s[i].c=c;
    }

    int ans=0;
    int mid=ceil((double)len/2.0);
    for(int l=1,r=n;l<r;){
        if(s[l].ed==rev(s[r].bg)){
            if(s[l].c!=s[r].c){
                ans+=min(s[l].ed,rev(s[r].bg))-max(s[l].bg,rev(s[r].ed))+1;
            }
            l++;
            r--;
        }
        else if(s[l].ed>rev(s[r].bg)){
            if(s[l].c!=s[r].c){
                ans+=min(s[l].ed,rev(s[r].bg))-max(s[l].bg,rev(s[r].ed))+1;
            }
            r--;
        }
        else{
            if(s[l].c!=s[r].c){
                ans+=min(s[l].ed,rev(s[r].bg))-max(s[l].bg,rev(s[r].ed))+1;
            }
            l++;
        }
    }

    cout<<ans<<endl;

    return 0;
}
