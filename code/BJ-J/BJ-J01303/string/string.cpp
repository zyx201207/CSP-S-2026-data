#include <bits/stdc++.h>
#define int long long
#define gc getchar_unlocked

using namespace std;

const int N=2e5+5;

int n;
int l[N],r[N];
char chr[N];
int ans=0;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    //freopen("string6.in","r",stdin);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> r[i] >> chr[i];
        l[i]+=r[i-1]; r[i]+=r[i-1];
    }

    int head=0,tail=r[n]-1,idx1=1,idx2=n;
    while(head<tail){
        int sz1=r[idx1]-head,sz2=tail-l[idx2]+1,minsz;
        minsz=min(sz1,sz2);
        if(chr[idx1]!=chr[idx2]){ans+=minsz;}
        head+=minsz; tail-=minsz;
        if(sz1==minsz){idx1++;}
        if(sz2==minsz){idx2--;}
    }

    cout << ans << endl;

    return 0;
}
