#include<bits/stdc++.h>
using namespace std;
map<int,int>p;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        string s;
        for(int j=i;j<=n;j++){
            if(s.find(a[j])!=string::npos){
                int k=s.find(a[j]);
                s.erase(k,s.size()-k+1);
            }
            s+=a[j];
        }
        for(char c:s)p[c]++;
    }
    for(int i=1;i<=m;i++)cout<<p[i]<<" ";
    return 0;
}