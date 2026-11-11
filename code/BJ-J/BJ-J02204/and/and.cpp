#include <bits/stdc++.h>
using namespace std;
int a[31][200005];
void bin(int s,int pos){
    int k;
    for(int i=30;i>=0;i--){
        if(s<=0)return;
        k=pow(2,i);
        if(s>=k){
            a[i][pos]=1;
            s-=k;
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    map<int,bool> p;
    int m,n,s,ans=0;
    cin >> m >> n;
    for(int i=0;i<m;i++){
        cin >> s;
        bin(s,i);
        p[i]=1;
    }//2e5*30=6e6 t=6e6 max 1.2e7
    int cur;//cur is a var that store the number of currently existing m<k(paper)
    ///*
    for(int i=30;i>=0;i--){
        int k=pow(2,i);
        cur=0;
        for(int j=0;j<m;j++){
            if((a[i][j]==1)&&(p[j]==1))cur++;
        }//not yet -> actually needn't to x, just scanning is ok
        if(cur>=n){
            ans+=k;//exist
            for(int j=0;j<m;j++)
                if(a[i][j]!=1)p[j]=0;
        }
    }
    cout << ans;
    return 0;//*/
}
