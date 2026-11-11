#include<bits/stdc++.h>
using namespace std;
struct node{
    int num;
    char c;
}a[200010];
int n;
long long cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].c;
    }
    int head=1,tail=n;
    while(head!=tail){
        if(a[head].c==a[tail].c){
            int o=max(a[head].num,a[tail].num);
            if(o==a[head].num){
                a[head].num=a[head].num-a[tail].num;
                a[tail].num=0;
                tail--;
            }else{
                a[tail].num=a[tail].num-a[head].num;
                a[head].num=0;
                head++;
            }
        }else{
            int o=max(a[head].num,a[tail].num);
            int v=min(a[head].num,a[tail].num);
            if(o==a[head].num){
                a[head].num=a[head].num-a[tail].num;
                a[tail].num=0;
                tail--;
            }else{
                a[tail].num=a[tail].num-a[head].num;
                a[head].num=0;
                head++;
            }
            cnt+=v;
        }
    }
    cout<<cnt;
    return 0;
}
