       #include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
    }
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[200005];
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    sort(a+1,a+n+1,cmp);
    cout<<a[m];
    fclose(stdin);
    fclose(stdout);

    return 0;
}


