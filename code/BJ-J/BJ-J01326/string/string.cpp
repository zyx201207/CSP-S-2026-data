#include<bits/stdc++.h>
using namespace std;
const int N=2e5+2;
long long n,p=1,q=0,x=1,y,sum=0,a[N][3];
char ch;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    y=n;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>ch;
        a[i][2]=q+1;
        q+=a[i][0];
        a[i][1]=int(ch-'a');
    }
    while(x<y){
        if(a[x][1]!=a[y][1]){
                sum+=(min(a[x+1][2],q-a[y][2])-p);
        }
        p=min(a[x+1][2],q-a[y][2]);
        if(a[x+1][2]>q-a[y][2]) y--;
        else x++;
    }
    cout<<sum;
    return 0;
}
