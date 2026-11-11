#include<bits/stdc++.h>

using namespace std;
char x[10001];
string p,xo;
int n,cnt;
int pi[10001];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>pi[i];
        cin>>x[i];

    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=pi[i];j++){
            p+=x[i];
        }

    }
    for(int i=p.size();i>=1;i++){
            cin>>xo[i];

    }

for(int i=p.size();i>=1;i++){
        if(p[i]!=xo[i]){
            cnt+=1;
        }
    }
    cout<<cnt+2;
    return 0;
}
