#include <bits/stdc++.h>
using namespace std;
queue<int> q;
queue<int> p;
vector<int> a;
vector<int> b;
vector<int> c;
int n,m;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1; i<=n; i++){
        cin>>a[i];
        q.push(a[i]);
    }
    for (int i=1; i<=m; i++){
        b[i]=i;
    }
    while (!q.empty()||!p.empty()){
        p.push(q.front());
        q.pop();
        if (p.front()==q.front()){
            while (!p.empty()) p.pop();
        }
        while (!p.empty()){
            int i=1;
            if (b[i]==q.front()) c[i]++;;
            p.pop();
        }
        for (int i=1; i<=n; i++){
            cin>>a[i];
            q.push(a[i]);
        }

    }
    for (int i=1; i<=c.length(); i++){
        cout<<c[i]<<" ";
    }
    return 0;
}
