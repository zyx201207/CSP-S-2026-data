#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
long long li[20005];
long long n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>li[i];
    }

    sort(li+1,li+1+n,cmp);
    long long maxx=INT_MIN;
    for(int i=1;i<=n;i++){
        long long a=li[i];
        for(int j=1;j<m;j++){
            a=a&li[i+j];
        }
        if(a>maxx){
            maxx=a;
            //cout<<a<<endl;
        }//cout<<maxx<<endl;
    }
    cout<<maxx;
    return 0;
}/*

5 3

31 3 1 15 7





*/
