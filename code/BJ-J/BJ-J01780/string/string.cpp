#include<bits/stdc++.h>
using namespace std;
struct node{
    int l;
    char c;
}a[200006];
stack<node> s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long ans = 0,l1 = 0;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>a[i].l>>a[i].c;
        l1+=a[i].l;
    }
    l1=l1/2;
    bool f = l1%2;
    int i;
    for(i = 0;i < n;i++){
        if(l1>a[i].l){
            s.push({a[i].l,a[i].c}),l1-=a[i].l;
        }
        else{
            s.push({l1,a[i].c}),a[i].l-=int(l1);
            if(f){
                if(a[i].l)a[i].l--;
                else a[i+1].l--;
            }
            break;
        }
    }
    for(;i<n;i++){
        //cout<<s.top().l<<endl;
        while(!s.empty()){
            bool m=1;
            if(a[i].c==s.top().c)m = 0;
            if(a[i].l>=s.top().l)a[i].l-=s.top().l,ans+=s.top().l*m,s.pop();
            else {
                ans+=a[i].l*m,s.top().l-=a[i].l;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
