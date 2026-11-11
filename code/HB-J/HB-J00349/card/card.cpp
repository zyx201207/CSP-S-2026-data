#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300010],b[500010],c[300010];
int r;
void push(int x){
    a[++r]=x;
}
void pop(){
    r--;
}
int front(){
    return a[r];
}
bool cha(int x){
    for(int i=0;i<r;i++){
        if(a[i]==x){
            return 1;
        }
    }
    return 0;
}
int main(){
//    freopen("card.in","r",stdin);
//    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(cha(b[j])){
                while(front()==b[j]){
                    pop();
                }
            }else{
                push(j);
            }
        }
        while(r>0){
            c[front()]++;
            pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}
