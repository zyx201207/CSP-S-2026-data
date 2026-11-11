#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1;
int n,len,ans;
struct range{
    int len;
    char c;
};
vector<range> s,s1,s2;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        s.push_back({a,c});
        len+=a;
    }
    s1.push_back({1,'*'});
    s2.push_back({1,'*'});
    int now=0;
    for(int i=0;i<n;i++){
        range r=s[i];
        now+=r.len;
        if(now<=len/2)s1.push_back({r.len,r.c});
        if(now>len/2&&now-r.len<len/2)s1.push_back({len/2-(now-r.len),r.c});
    }
    now=0;
    for(int i=n-1;i>=0;i--){
        range r=s[i];
        now+=r.len;
        if(now<=len/2)s2.push_back({r.len,r.c});
        if(now>len/2&&now-r.len<len/2)s2.push_back({len/2-(now-r.len),r.c});
    }
    s1.push_back({1,'*'});
    s2.push_back({1,'*'});
    int start1=1,end1=s1[0].len,start2=1,end2=s2[0].len,i=0,j=0;
    while(i!=s1.size()-1||j!=s2.size()-1){
        if(start1>=start2&&end1<=end2){
            if(s1[i].c!=s2[j].c)ans+=end1-start1+1;
            if(i+1<s1.size()){
                start1=end1+1;
                end1=start1+s1[++i].len-1;
            }
        }
        else if(start2>=start1&&end2<=end1){
            if(s1[i].c!=s2[j].c)ans+=end2-start2+1;
            if(j+1<s2.size()){
                start2=end2+1;
                end2=start2+s2[++j].len-1;
            }
        }
        else if(start1<=start2){
            if(s1[i].c!=s2[j].c)ans+=end1-start2+1;
            if(i+1<s1.size()){
                start1=end1+1;
                end1=start1+s1[++i].len-1;
            }
        }
        else if(start2<=start1){
            if(s1[i].c!=s2[j].c)ans+=end2-start1+1;
            if(j+1<s2.size()){
                start2=end2+1;
                end2=start2+s2[++j].len-1;
            }
        }
    }
    cout<<ans;
    return 0;
}
