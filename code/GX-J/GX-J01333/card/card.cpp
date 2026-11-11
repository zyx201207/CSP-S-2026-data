#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int a[500005],b[300005],c[500005];
    queue<int>q,p,o,e;
    for(int i=0;i<n;i++){
        cin>>a[i];
        q.push(a[i]);
    }
    for(int i=0;i<m;i++){
        for(int f=0;f<n;f++){
            p.push(q.front());
            int l=p.size();
            c[l-1]=q.front();
            for(int j=0;j<l-1;j++){
                if(c[j]==q.front()){
                    for(int k=0;k<j;k++){
                        e.push(p.front());
                        p.pop();
                    }
                    for(int k=j;k<l;k++){
                        o.push(p.front());
                        p.pop();
                    }
                    for(int k=0;k<l-j;k++){
                        p.push(e.front());
                        e.pop();
                    }
                }
            }
            int z=o.size();
            int s=p.size();
            if(z+s==n)
            for(int j=0;j<s;j++){
                b[p.front()-1]++;
                o.push(p.front());
                p.pop();
            }
        }
        for(int f=0;f<n;f++)
            q.pop();
        for(int f=0;f<n;i++){
            q.push(o.front());
            o.pop();
        }
    }
    for(int i=0;i<m;i++)
        cout<<b[i]<<" ";
    return 0;
}
