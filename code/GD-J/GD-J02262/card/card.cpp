#include <bits/stdc++.h>
using namespace std;
stack <int> s;

int a[300005];
int b[300005];
int num[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]=x;
    }
    bool p=true;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (a[i]==a[j]){
                p=false;
            }
        }
    }
    if (p){
        for (int i=0;i<m;i++){
            cout<<i+1;
            if (i!=m-1){
                cout<<" ";
            }
        }
        return 0;
    }
    for (int i=0;i<m;i++){
        s.empty();
        for (int j=i;j<n;j++){
            if (b[a[j]]==0){
                s.push(a[j]);
                b[a[j]]++;

            }
            else{
                int x=s.top();
                if (x!=a[j]){
                    s.pop();
                    b[x]-=1;
                }
            }
        }
        for (int k=0;k<n;k++){
            if (b[k]!=0){
                num[k]+=1;
            }
        }

        for (int i=0;i<n;i++){
            b[i]=0;
        }
    }
    for (int i=0;i<m;i++){
        cout<<num[i];
        if (i!=m-1){
            cout<<" ";
        }
    }
    return 0;
}
