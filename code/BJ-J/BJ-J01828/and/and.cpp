#include<bits/stdc++.h>
using namespace std;
struct www{
    long long val;
    bool a[35]={0};//dao xu,gao wei zai hou,mo wei dui qi
    int l;
    int c1;
};
www a[20005];

bool cmp(www x,www y){
    return x.l>y.l;
    if(x.l==y.l){
        return x.val>y.val;
    }
}

void ttt(www &t){
    long long ten=t.val;
    t.l=0;
    while(ten>0){
        if(ten%2==1)t.c1++;
        t.a[t.l]=ten%2;
        ten=ten/2;
        t.l++;
    }
    //for(int i=0;i<=t.l-1;i++)cout<<t.a[i];
    //cout<<endl;
}

www cal(www x,www y){
    www neww;
    neww.l=min(x.l,y.l);
    neww.val=0;
    for(int i=0;i<neww.l;i++){
        if(x.a[i]==1&&y.a[i]==1)neww.a[i]=1;
        else neww.a[i]=0;
    }
    //for(int i=0;i<neww.l;i++)cout<<neww.a[i];
    //cout<<endl;
    int now=1;
    for(int i=0;i<neww.l;i++){
        neww.val+=now*neww.a[i];
        now*=2;
    }
    //cout<<x.val<<' '<<y.val<<':'<<neww.val<<endl;
    return neww;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].val;
        ttt(a[i]);
    }
    sort(a+1,a+n+1,cmp);
    www pre=a[1];
    for(int i=2;i<=m;i++){
        pre=cal(pre,a[i]);
    }
    cout<<pre.val<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
