#include<bits/stdc++.h>
using namespace std;
typedef long long LO;
LO n,m,c,d,w,s;
LO a[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    d=1;
    for(int i=1;i<n;i++){
        c=1;
        w=i-1;
        s=m;
        while(w>=0){
            if(s-(a[i]-a[w])>=0){
                s-=(a[i]-a[w]);
                c++;
                w--;
            }else{
                break;
            }
        }
        d=max(d,c);
    }
    cout<<d;
    fclose(stdin);
    fclose(stdout);
    return 0;
}