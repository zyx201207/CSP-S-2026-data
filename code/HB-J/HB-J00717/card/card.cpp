#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],e[500005];
string s,s1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[a[i]]++;
        s=s+char(a[i]+48);
    }
    for(int i=1;i<=n;i++){
        s1=s;
        int x=1;
        while(x){
            for(int j=i;j<=m;j++){
                int p=s1.find(j+48);
                if(p!=string::npos){
                    int p1=s1.find(j+48,p+1);
                    if(p1!=string::npos){
                        s1.erase(p,p1-p);
                    }
                }
            }
            int f=1;
            for(int j=i;j<=m;j++){
                int p=s1.find(j+48);
                if(p!=string::npos){
                    int p1=s1.find(j+48,p+1);
                    if(p1!=string::npos){
                        f=0;
                        break;
                    }
                }
            }
            if(f)x=0;
        }
        for(int j=i-1;j<s1.size();j++){
            e[s1[j]-48]++;
        }
    }
    for(int i=1;i<=m;i++)cout<<e[i]<<' ';
    return 0;
}
