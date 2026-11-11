#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
#define endl '\n'
int a[500010],s[500010],m,n;
int sal[500010];
map<int,int>mp;
bool check(int x){
    for(int l=0;l<=n-x/*l+x-1=r<n,l+x-1<n,l+x<=n*/;l++){
        if((sal[l+x-1]-sal[l])-l*(s[l+x-1]-s[l])<=m){
            return 1;
        }
    }
    return 0;
}
void solve(){
    cin>>n>>m;
    //cout<<m<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
        //mp[a[i]]++;
    }
    sort(a,a+n);
    for(int i=1;i<n;i++){
        s[i]=s[i-1]+a[i]-a[i-1];
        sal[i]=sal[i-1]+(a[i]-a[i-1])*i;
    }
    //int anss=sal[n-1];
    //cout<<anss<<endl;
    //for(int i=1;i<n;i++){
    //    cout<<s[i]<<' ';
    //}
    //cout<<endl;
    //for(int i=1;i<n;i++){
    //    cout<<sal[i]<<' ';
    //}
    int l=1,r=6e5,o=l;
    while(l<=r){
        int mid=(l+r)/2;
        //cout<<l<<' '<<mid<<' '<<r<<' '<<o<<endl;
        if(check(mid)){
            l=mid+1;
            o=mid;
        }
        else{
            r=mid-1;
        }
    }//check成了就进一步，反之退
    cout<<o<<endl;
}
/*
花费为sal[r]-sal[l]-l*(s[r]-s[l])
带来收益r-l+1
考虑二分答案
向右长度
nlogn?
*/
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    //freopen("crystal1.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
/*
14:30
A:从低到高向上增加一定不劣
B:强化版的A，强了一点
14:40
没有思路
14:45
前缀和行不行?
1 2 4 8 9
0 1 5 17 21 sal
0 1 3 7 8  s
1 2 3 4 4
0 1 2 3 3
0 1 3 6 6
6-3-2*(3-2)
3-2=1
(r-l)-(r-l)*l
(21-1)-(8-1)
20-7=13
(21-5)=16
16-(8-3)*2=6
5+1=6


17-0=17
17-1=16
6+4=10
17-5=12
12-4*2=4
15:30
4samp ac
1h +100
我的同学的luogu名是yzy20120617请关注ta
我的同学的luogu名是An_Inch_Of_Ash请关注ta
我的同学的luogu名是汞_1020请关注ta（汞换成英文）
*/
