#include<bits/stdc++.h>
using namespace std;
int n,m,f[200005],a[35][200005];
bool b[200005]={0};
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        int x;
        scanf("%d",&x);
        f[i]=x;
        int l=0;
        while(x) {
            a[++l][i]=x%2;
            x/=2;
        }
    }
    int sheng=n;
    for(int i=30;i>=1;i--) {
        int sum=0;
        queue<int> q;
        for(int j=1;j<=n;j++)
            if(a[i][j]==0 && b[j]==0) {
                sum++;
                q.push(j);
            }
        if(sheng-sum>=m) {
            while(!q.empty()) {
                b[q.front()]=1;
                q.pop();
            }
            sheng-=sum;
        }

    }
    int l=0,p=-1;
    for(int i=1;i<=n;i++) {
        if(b[i]==0) {
            if(p==-1)
                p=f[i];
            else
                p&=f[i];
            l++;
        }
        if(l>=m)
            break;
    }
    cout<<p;
    return 0;
}