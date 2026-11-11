#include<iostream>
#include<deque>
using namespace std;
struct node{
    int64_t cnt;char c;
};deque<node>a;//deque nb!
int64_t sum=0LL;
void erase_(){
    if(a.front().cnt==a.back().cnt){
        a.pop_back();
        a.pop_front();
    }else if(a.front().cnt<a.back().cnt){
        a.back().cnt-=a.front().cnt;
        a.pop_front();
    }else{
        a.front().cnt-=a.back().cnt;
        a.pop_back();
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        node x;
        cin>>x.cnt>>x.c;
        if(a.empty())a.emplace_back(x);
        else if(a.back().c==x.c)
            a.back().cnt+=x.cnt;
        else
            a.emplace_back(x);
    }
    while(!a.empty()&&a.size()>=2){
        if(a.back().c!=a.front().c)
            sum+=min(a.back().cnt,a.front().cnt);
        erase_();
    }
    cout<<sum;
    //fclose(stdin);fclose(stdout);
    return 0;
}
