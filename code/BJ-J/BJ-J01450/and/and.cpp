#include<bits/stdc++.h>
using namespace std;
string s[200005];
long long sum;
bool cmp(string a,string b){
    if(a.size()!=b.size())return a.size()>b.size();
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        long long x;
        bool b=0;
        string str;
        cin>>x;
        int ans=30;
        while(x>0){
            if(x>=pow(2,ans)){
                x-=pow(2,ans);
                str+='1';
                b=1;
            }
            else{
                if(b)str+='0';
            }
            ans--;
        }
        while(ans>=0){
            str+='0';
            ans--;
        }
        s[i]=str;
    }
    string ans="111111111111111111111111111111111";
    sort(s+1,s+1+n,cmp);
    for(int i=1;i<=m;i++){
        string x;
        for(int j=0;j<min(s[i].size(),ans.size());j++){
            if(ans[j]=='1' && s[i][j]=='1')x+='1';
            else x+='0';
        }
        ans=x;
    }
    int c=ans.size()-1;
    for(int i=0;i<ans.size();i++){
        if(ans[i]=='1')sum+=pow(2,c);
        c--;
    }
    cout<<sum;
    return 0;
}