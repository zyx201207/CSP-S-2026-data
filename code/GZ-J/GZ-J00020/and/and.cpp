//姓名：李承峰 学校：观山湖区外国语实验中学 准考证号：GZ-J00020
#include<bits/stdc++.h>
using namespace std;

int n,m;
long long mn=0,mn1=0,mn2=0;
long long a[200010];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        long long d=a[i]&a[i-1];
        if(i==1){
            mn2=a[1];
        }
        mn=max(d,mn);
        mn1=max(mn1,a[i]);
        if(i>1){
            mn2=mn2&a[i];
        }
    }
    if(m==2){
        cout<<mn;
    }
    if(m==1){
        cout<<mn1;
    }if(m==n){
        cout<<mn2;
    }
    return 0;
}
