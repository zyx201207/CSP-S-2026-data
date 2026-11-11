#include <bits/stdc++.h>
using namespace std;
int last;
int a[500050];
int answer,ans;
void cl(int num,int leader){
    if(num>=1){
        int cha=a[leader]-a[num];
        if(last>=cha){
            last-=cha;
            ans++;
            cl(num-1,leader);
        }
    }
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        last=m;
        ans=1;
        cl(i-1,i);
        answer=max(answer,ans);
    }
    cout<<answer;
    return 0;
}
