#include<bits/stdc++.h>
using namespace std;
int n;
struct stu{
    long long a;
    char c;
}x[200005],y[200005];
bool f=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    cin>>x[1].a>>x[1].c;
    for(int i=2;i<=n;i++){
        cin>>x[i].a>>x[i].c;
        if(x[i].c!=x[i-1].c){
            f=1;
        }
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    if(f==0){
        cout<<0;
        return 0;
    }
    if(n==2){
        cout<<min(x[1].a,x[2].a);
        return 0;
    }
    if(n==3){
        if(x[1].a==x[3].a&&x[1].c==x[3].c){
            cout<<0;
            return 0;
        }else{
            cout<<max(x[1].a,x[3].a);
            return 0;
        }
    }
    int w=1;
    for(int i=1;i<=n;i++){
        if(x[i].c==x[i+1].c){
            y[w].a+=x[i].a;
        }else{
            y[w].a+=x[i].a;
            y[w].c=x[i].c;
            w++;
        }
    }
    w--;
     if(w==2){
        cout<<min(y[1].a,y[2].a);
        return 0;
    }
    if(w==3){
        if(y[1].a==y[3].a&&y[1].c==y[3].c){
            cout<<0;
            return 0;
        }else{
            cout<<max(y[1].a,y[3].a);
            return 0;
        }
    }
    long long h=0;
    for(int i=1;i<=w;i++){
        h+=y[i].a;
    }
    cout<<h/2;
    return 0;
}
