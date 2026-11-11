#include<bits/stdc++.h>
using namespace std;
struct Node{
    char c;
    long long num;
};
void out(queue<Node> q){
    for(int i=0;i<=q.size();i++){
        Node v = q.front();q.pop();
        cout<<v.c<<"_"<<v.num<<' ';
    }
    cout<<'\n';
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    vector<Node> v;
    long long sum=0;
    queue<Node> g,h;
    for(int i=1;i<=n
    ;i++){
        Node x;
        cin>>x.num>>x.c;
        v.push_back(x);
        sum+=x.num;
    }
    long long tmp=0;
    for(int i=0;i<n;i++){
        if(tmp>=sum/2)break;
        Node m = v[i];
        m.num = (sum/2-tmp<m.num?sum/2-tmp:m.num);
        tmp+=m.num;
        g.push(m
               );
    }
    tmp = 0;
    for(int i=n-1;i>=0;i--){
        if(tmp>=sum/2)break;
        Node m = v[i];
        m.num = min(sum/2-tmp,m.num);
        tmp+=m.num;
        h.push(m);
    }
    long long cnt=0;Node x = g.front(),y = h.front();g.pop();h.pop();
    for(int i=1;i<=n;i++){
        if(x.c==y.c){
            if(x.num>y.num){
                x.num = x.num-y.num;
                y=h.front();h.pop();
            }
            else if(x.num==y.num){
                x = g.front(),y = h.front();g.pop();h.pop();
            }
            else if(x.num<y.num){
                y.num = y.num-x.num;
                x=
                g.front();g.pop();
            }
        }
        else{
            if(x.num>y.num){
                cnt+=y.num;
                x.num = x.num-y.num;
                y=h.front();h.pop();
            }
            else if(x.num==y.num){
                cnt+=x.num;
                x = g.front(),y = h.front();g.pop();h.pop();
            }
            else if(x.num<y.num){
                cnt+=x.num;
                y.num = y.num-x.num;
                x=g.front();g.pop();
            }
        }
    }
    cout<<cnt;
}

