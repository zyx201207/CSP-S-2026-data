 #include<bits/stdc++.h>
 using namespace std;
 int a[200050];
 int main(){
     freopen("and.in","r",stdin);
     freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int b=a[n-1];
    for(int i=n-m;i<n-1;i++){
        b&=a[i];
    }
    cout<<b;
    return 0;
 }
