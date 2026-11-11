#include<bits/stdc++.h>
using namespace std;
char t[200005];
struct wei{
    int s,y,tick=1;
};
wei a[200005],nw[500005];
char tt(int n){
    stack<int> st;
    while(n>0){
        st.push(n%2);
        n/=2;
    }
    char c=0;
    while(!st.empty()){
        c+=char(st.top());
        st.pop();
    }
    return c;
}
int con(int n){
    stack<int> st;
    int k=0;
    while(n>0){
        st.push(n%2);
        n/=2;
        k+=1;
    }
    return k;
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i].s;
        nw[i].s=a[i].s;
        nw[i].y=nw[i].s%2;
    }
    sort(a[1].s+1,a[n+1].s);
    int len=con(a[n+1].s);
    if(m==1) cout << a[n+1].s;
    while(n>=1){
        int c1,c2,c=0;
        for(int x=1;x<=len;x++){
            for(int i=1;i<=n;i++){
                if(nw[i].tick==1&&nw[i].y!=0){
                    nw[i].y=(nw[i].s/2)%2;
                    nw[i].s/=2;
                    c++;
                }
            }
            if(c==1){
                for()
            }
        }
    }
    return 0;
}
