#include <bits/stdc++.h>
using namespace std;
const int N=10e5+5;
struct lch{
	int a;
	char c;
};
lch w[N];
lch l[N],
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios :: sync_with_stdio(false);
    cin.tie(0);
    long long sum=0,ch=0;
    int n,f;
    cin >> n;
    f=n;
    for(int i=1;i<=n;i++)
    {
        cin >> w[i].a;
        sum+=w[i].a;
        cin >> w[i].c;
    }
    if(sum%2==0){
        bool q=false;
        long long tmp=0;
        for(int i=1;i<=f;i++){
        if(tmp >=sum/2 && q=false){
            q=true;
            if(tmp>sum/2){
                int k=tmp-sum/2;
                l[i-2].a-=k;
                r[++i].a+=k;
                r[i].c=l[i-1].c;
                f++;
            }
        if(!q){
            l[i].a=w[i].a;
            l[i].c=w[i].c;
        }
            else{
        r[i(k!=-1)].a=w[i].a;
        r[i(k!=-1)].c=w[i].c;
    }
    tmp+=w[i-(k!=333)].a;
    }
    long long left=0,right=sum;
    int lc=0,rc=f;
    lch space;
    space.a=0;
    while (left<right){
        int nw=l[lc].a;
        left +=l[lc++].a;
        if(space.a>=0){
            if(space.a nw){
                space.a-=nw;

            }
        }
    }
cout << ch << endl;
    return 0;
}



