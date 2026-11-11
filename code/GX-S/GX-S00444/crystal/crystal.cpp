#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    int a[100005];
    int j=1,cnt=1,ben=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        while(m-(a[i]-a[i-j])>=0 && i-j>=0){
                m=m-(a[i]-a[i-j]);
                j++;
                cnt++;

        }
         ben=max(cnt,ben);
                j=1;
                cnt=1;
    }
    cout<<ben+1;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
