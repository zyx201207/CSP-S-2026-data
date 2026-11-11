#include<iostream>
#include<stack>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m,a[500005];
int ans[300005];
bool t[300005];
stack<int> s;
void insert(int x){
    if(!t[x]){
        t[x]=1;
        s.push(x);
    }else{
        while(s.top()!=x){
            t[s.top()]=0;
            s.pop();
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            insert(a[j]);
        }
        //cout<<i<<":\n";
        for(int j=1;j<=m;j++){
            if(t[j]) ans[j]++;
            //cout<<j<<":"<<t[j]<<"    ";
        }
        //cout<<endl;
        while(!s.empty()) s.pop();
        memset(t,0,sizeof(t));
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
