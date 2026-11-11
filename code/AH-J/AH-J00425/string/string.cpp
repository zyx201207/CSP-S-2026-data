#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int a;
    char c;
};
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    int sum=0;
    vector<node>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].a>>a[i].c;
        sum+=a[i].a;
    }
    int ans=0;
    int ln=0;
    int l=0;
    int r=sum-1;
    int rn=n-1;
    while(r-l>1){
        if(a[ln].a>a[rn].a){
            if(a[ln].c!=a[rn].c){
                ans+=a[rn].a;
            }
            a[ln].a-=a[rn].a;
            l+=a[rn].a;
            r-=a[rn].a;
            rn--;

        }
        else if(a[ln].a<a[rn].a){
            if(a[ln].c!=a[rn].c){
                ans+=a[ln].a;
            }
            a[rn].a-=a[ln].a;
            l+=a[ln].a;
            r-=a[ln].a;
            ln++;
        }
        else if(a[ln].a==a[rn].a){
            if(a[ln].c!=a[rn].c){
                ans+=a[rn].a;
            }
            l+=a[ln].a;
            r-=a[ln].a;
            ln++;
            rn--;
        }
    }
    cout<<ans;
    /*
    int aa=s.size();
    int ans=0;
    if(aa%2==0){
        for(int i=0;i<aa/2;i++){
            if(s[i]!=s[aa-1-i])ans++;
        }
    }
    if(aa%2==1){
        for(int i=0;i<(aa-1)/2;i++){
            if(s[i]!=s[aa-1-i])ans++;
        }
    }
    cout<<ans;*/
    return 0;
}
