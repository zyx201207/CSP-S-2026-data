#include<bits/stdc++.h>
using namespace std;
bool findtwo(int x,int k){
    return ((x>>(k-1))&1);
}
struct node{
    int next,val;
}a[300010];
int lazy[300010];
bool cmp(const node &a,const node&b){return a.val>b.val;}
void killa(int i){
    a[i].next=a[a[i].next].next;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].val;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=0;i<n;i++)a[i].next=i+1;
    a[n].next=0;a[0].val=(1<<31)-1;
    int mask=0;
    int pp=a[1].val;int p=0;while(pp>0){pp=pp>>1;p++;}
    while(p>=0){
        bool last=1;
        int sum=0,ans=0;
        for(int i=0;((a[i].next)!=0);i=a[i].next){
            node now=a[a[i].next];
            while(!findtwo(now.val,p)){
                if(sum>=m){
                    killa(i);
                    now=a[a[i].next];
                    if(a[i].next==0)break;
                }
                else{
                    lazy[++ans]=i;
                    sum--;
                    break;
                }
            }
            sum++;
        }
        if(sum>=m){
            for(int i=1;i<=ans;i++)killa(lazy[i]);
            mask+=(1<<(p-1));
        }
        for(int i=1;i<=ans;i++)lazy[i]=0;
        p--;
    }
    cout<<mask;
    return 0;
}
