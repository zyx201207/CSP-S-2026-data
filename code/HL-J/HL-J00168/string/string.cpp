#ifndef STRING_CPP_INCLUDED
#define STRING_CPP_INCLUDED
#include <bits/stdc++.h>
using namespace std;
long long a[200010],qzh[21111];
int n;
char c[20010];
char which_letter(int num){
    int temp=upper_bound(qzh,qzh+n+1,num)-qzh;
    return c[temp];
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        qzh[i]=qzh[i-1]+a[i];
        sum+=a[i];
    }
    for(int i=1;i<=n;i++){
        qzh[i]+=1;
    }
    int cnt=0;
    for(int i=1;i<=sum/2;i++){
        if(which_letter(i)!=which_letter(sum+1-i)){
            cnt++;
        }
        /*int n1=upper_bound(qzh,qzh+n+1,i)-qzh;
        int n2=upper_bound(qzh,qzh+n+1,sum+1-i)-qzh;
        cout<<n1<<' '<<n2<<endl;*/
    }
    cout<<cnt;
    return 0;
}
/*#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[3]={3,4,6};
    int aq=2;
    int bq=upper_bound(a,a+3,aq)-a;
    cout<<bq;
    return 0;
}*/
#endif // STRING_CPP_INCLUDED
