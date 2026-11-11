#include<bits/stdc++.h>
using namespace std;
vector<int>a;
int v[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,k;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        a.push_back(k);
    }
    for(int i=0;i<n;i++){
        string s;
        for(int l=i;l<n;l++){
            char k=48+a[l];
            int c=s.find(k);
            if(c!=-1){
                s=s.substr(0,c);
            }
            s+=k;
        }
        for(int l=0;l<s.size();l++){
            int c=s[l]-48;
            v[c]++;
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d ",v[i]);
    }





    return 0;
}
