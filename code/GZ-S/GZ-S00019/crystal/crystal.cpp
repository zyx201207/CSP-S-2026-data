//姓名：李承峰 学校：观山湖区外国语实验中学 准考证号：GZ-S00019
#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[100010];
int k;

int bl(int y){
    if(a[y]<a[y+1])return y;
    if(a[y]==a[y+1])return bl(y+1);
}

int f(){
    for(int i=1;i<=n;i++){
        if(a[i]<=a[i+1]){
            a[i]++;
            if(a[i]<a[i+1]){
                return i;
            }else if(a[i]==a[i+1]){
                return bl(i+1);
            }
        }
    }
}

int mx(){
    int maxn=1;
    int cnt=1;
    for(int i=1;i<=n;i++){
        if(a[i]==a[i-1]){
            cnt++;
            maxn=max(maxn,cnt);
        }else{
            cnt=1;
        }
    }
    return maxn;
}



int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[i]=x;
    }
    sort(a+1,a+n+1);
    while(m>0){
        k=f();
        m--;
    }
    if(m==0){
        k=mx();
    }
    cout<<k;
    return 0;
}
