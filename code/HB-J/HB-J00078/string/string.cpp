#include<bits/stdc++.h>
using namespace std;
struct node{
    int a;
    char ch;
}p[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    /*
    string s = "";
    for(int i = 1;i <= n;i++){
        int a;
        char ch;
        cin>>a>>ch;
        for(int j = 1;j <= a;j++){
            s = s + ch;
        }
    }
    int len = s.size();
    int cnt = 0;
    for(int i = 0;i < len;i++){
        if(s[i] != s[len - i - 1]){
            cnt++;
        }
    }
    cout<<cnt / 2;
    cout<<"\n"<<s;
    */
    for(int i = 1;i <= n;i++){
        cin>>p[i].a>>p[i].ch;
    }
    long long ans = 0;
    int l = 1,r = n;
    while(l < r){
        if(p[l].ch != p[r].ch){
            int mn = min(p[l].a,p[r].a);
            ans += mn;
            p[l].a -= mn;
            p[r].a -= mn;
            if(p[l].a <= 0) l++;
            if(p[r].a <= 0) r--;
        }
        else{
            int mn = min(p[l].a,p[r].a);
            p[l].a -= mn;
            p[r].a -= mn;
            if(p[l].a <= 0) l++;
            if(p[r].a <= 0) r--;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
