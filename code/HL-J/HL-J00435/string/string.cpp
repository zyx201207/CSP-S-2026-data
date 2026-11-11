#include<bits/stdc++.h>
using namespace std;
int n,a[200010],maxn;
char c[200010];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i]>>c[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i];j++){
            s+=c[i];
        }
    }
    for(int i=0;i<s.size()-1;i++){
        for(int j=i;j<s.size()-1;j++){
            string s1,s2;
            for(int k=i;k<=j;k++) s1+=s[k];
            for(int k=s1.size()-1;k>=0;k--) s2+=s1[i];
            if(s1==s2&&maxn<s1.size()) maxn=s1.size();
        }
    }
    cout<<s.size()-maxn-1;
    return 0;
}
