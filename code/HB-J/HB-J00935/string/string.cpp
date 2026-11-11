#include<bits/stdc++.h>
using namespace std;
struct lo{
    long long num;
    char c;
};
lo a[200005];
lo b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].c;
        b[n-i+1].num=a[i].num;
        b[n-i+1].c=a[i].c;
    }
    long long sum=0,id=-1,t;
    int j=1,i=1;
    for(;i<=n&&j<=n;){
        t=min(b[j].num,a[i].num);
        a[i].num=a[i].num-t;
        b[j].num=b[j].num-t;
        if(b[j].c!=a[i].c){
            sum+=t;
        }
        if(a[i].num==0){
            if(b[j].num==0){
                i++;
                j++;
            }
            else{
                i++;
            }
        }else{
            j++;
        }

    }

    cout<<sum/2;
    return 0;
}
