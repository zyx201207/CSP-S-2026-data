#include<bits/stdc++.h>
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
stack<pair<long long,int> >s;
queue<pair<long long,int> >q;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    long long n;
    cin>>n;
    long long a;
    char c[1];
    for(int i=0;i<n;i++){
        cin>>a>>c;
        //out<<c[0];
        s.push(make_pair(a,(c[0]-'a')));
        q.push(make_pair(a,(c[0]-'a')));
    }
    pair<int,int> frt,bck;
    frt=s.top();
    bck=q.front();
    s.pop();
    q.pop();
    int lenth;
    while((!q.empty())||(!s.empty())){
        if(frt.first>bck.first){
            lenth=frt.first-bck.first;
            if(frt.second!=bck.second){
                ans+=bck.first;
            }
            bck=q.front();
            q.pop();
            frt.first=lenth;
        }
        else if(frt.first<bck.first){
            lenth=bck.first-frt.first;
            if(frt.second!=bck.second){
                ans+=frt.first;
            }
            frt=s.top();
            s.pop();
            bck.first=lenth;
        }else if(frt.first==bck.first){
            if(frt.second!=bck.second){
                ans+=frt.first;
            }
            frt=s.top();
            bck=q.front();
            s.pop();
            q.pop();
        }
    }
    if(frt.second!=bck.second){
        ans+=frt.first;
    }
    cout<<((ans)>>1);
    return 0;
}
