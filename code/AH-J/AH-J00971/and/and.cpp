#include<bits/stdc++.h>
using namespace std;
int a[200005];
vector<string>t[35];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        string s;
        int p=a[i];
        while(p!=0){
            int x=p%2;
            char c=x+'0';
            s=c+s;
            p=p/2;
        }
        while(s.size()<30){
            s="0"+s;
        }
        for(int j=0;j<30;j++){
            if(s[j]=='1'){
                t[30-j].push_back(s);
            }
        }
    }
    int mx=-1;
    for(int i=1;i<=30;i++){
        string ans;
        for(int j=1;j<=30;j++){
            if(t[i].size()<m){
                break;
            }
            int sum=0;
            vector<string> q;
            for(int k=0;k<t[i].size();k++){
                if(t[i][k][j]=='0'){
                    q.push_back(t[i][k]);
                    sum++;
                }
            }
            if(t[i].size()-sum>m){
                ans="1"+ans;
            }else{
                ans="0"+ans;
            }
        }
        int u=0;
        int jinlu=1;
        for(int i=ans.size()-1;i>=0;i--){
            if(ans[i]=='1'){
                u=u+jinlu;
            }
            jinlu*=2;
        }
        mx=max(mx,u);
    }
    cout<<mx;
return 0;
}
