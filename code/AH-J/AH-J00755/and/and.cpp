#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
int a[200005],ans[200005];
bool cmp(int x,int y){
    return x<y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        int l=i,r=i+m;
        ans[i]=a[l];
        while(l<r){
            l++;
            string s,a1,b1;
            int ab=ans[i],b=a[i];
            while(ab!=0){
                a1+=(ab%2)+'0';
                ab/=2;
            }
            while(b!=0){
                b1+=(b%2)+'0';
                b/=2;
            }
            int q=a1.size();
            int p=b1.size();
            int si=max(p,q);
            while(si>min(p,q)){
                if(q<p) a1+='0';
                else b1+='0';
                si--;
            }
            for(int j=0;j<max(p,q);j++){
                if(a1[j]==b1[j]) s+='1';
                else s+='0';
            }
            for(int j=0;j<s.size();j++){
                int x=s[j]-'0';
                int l=j;
                if(l){
                    while(l--){
                        x*=2;
                    }
                }
                ans[i]+=x;
            }
        }
    }
    for(int i=1;i<=n;i++){
        sum=max(sum,ans[i]);
    }
    cout<<sum;
    return 0;
}
