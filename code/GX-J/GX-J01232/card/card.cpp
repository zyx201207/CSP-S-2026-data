#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> b(n+1);
int fd(vector<int> a,int x){
    int cnt=0;
    for(int i=1;i<=a.size();i++)if(a[i]==x)cnt++;
    return cnt;
}
void f(vector<int> b,int x){
    vector<int> t(n+1);
    if(fd(b,x)!=0){
        for(int i=1;i<=b.size();i++){
            if(b[i]!=x)t.push_back(b[i]);
            else break;
        }
        t.push_back(x);
        vector<int> b(n+1,0);
        for(int i=0;i<t.size();i++){
            b[i+1]=t[i];
        }
        return ;
    }else {
        b.push_back(x);
        return ;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    vector<int> a(n+1);
    vector<int> b(n+1);
    vector<int> sum(m+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
         vector<int> b(n+1,0);
        for(int j=i;j<=n;j++){
            f(b,a[j]);
        }
        for(int z=1;z<=m;z++)if(fd(b,z)!=0)sum[z]++;
    }
    for(int i=1;i<=m;i++)cout<<sum[i]<<" ";
}
