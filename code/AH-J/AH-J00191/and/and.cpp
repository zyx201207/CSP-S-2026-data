#include<bits/stdc++.h>
using namespace std;
int m,n,a[200005],b=0,d;
string s,s1,c;
void er(int x){
    int l[31];
    string l1;
    if(x==0||x==1){
        l[b]=x;
        for(int i=b,i>=0;i+--){
            l1[b-i]=char(l[i]+'0');
        }
        return l1;
    }
    else {
        l[b]=(x%2);
        b++;
        er(x/2);
    }
}
int main(){
    freopen("and.in","r".stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=m;i++){
        for(int j=n;j>=n-m;j--){
            s=er(a[j]);
            d=max(s.size(),c.size);
            for(int k=0;k<=l;k++){
                if(s[k]==c[k])c[k]='1';
                else c[k]=='0';
            }
        }
    }
    for(int i=0;i<=d;i++)cout<<c[i];
    return 0;
}
