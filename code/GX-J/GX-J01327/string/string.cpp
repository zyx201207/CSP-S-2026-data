#include<bits/stdc++.h>
using namespace std;
struct dl{
    int l;
    char c;
}a;
deque<dl> s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long cnt=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a.l>>a.c;
        s.push_back(a);
    }
    char cri=s.front().c,crj=s.back().c;
    while(n>=1){
        if(cri!=crj)cnt++;
        if(!s.empty()){
            s.front().l--;
            s.back().l--;
            if(s.front().l<=0){
                s.pop_front();
                n--;
            }
            if(s.empty())break;
            if(s.back().l<=0){
                s.pop_back();
                n--;
            }
            if(s.empty())break;
            cri=s.front().c;
            crj=s.back().c;
        }else break;
    }
    cout<<cnt;
    return 0;
}
