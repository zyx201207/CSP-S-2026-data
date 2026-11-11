#include<bits/stdc++.h>
using namespace std;
int n;
long long current_absolute_pos;
int front_node,back_node;
long long front_offset,back_offset;
long long tot_len,ans;
int a[200002],ch[200002];
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%s",a+i,&c);
        ch[i]=c-'a';
        tot_len+=a[i];
    }
    front_node=1,back_node=n;
    while(front_node<back_node){
        long long front_rem=a[front_node]-front_offset;
        long long back_rem=a[back_node]-back_offset;
        if(front_rem<back_rem){
            if(ch[front_node]!=ch[back_node]){
                ans+=front_rem;
            }
            front_node++,front_offset=0;
            back_offset+=front_rem;
        }
        else if(front_rem==back_rem){
            if(ch[front_node]!=ch[back_node]){
                ans+=front_rem;
            }
            front_node++,front_offset=0;
            back_node--,back_offset=0;
        }
        else{
            if(ch[front_node]!=ch[back_node]){
                ans+=back_rem;
            }
            back_node--,back_offset=0;
            front_offset+=back_rem;
        }
    }
    printf("%lld\n",ans);
}