#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int cnt=0;
    int a[n+5];
    string c[n+5];
    for(int j=0;j<n;j++){
        cin>>a[j]>>c[j];
    }
    string z;
    for(int q=0;q<n;q++){
        for(int w=0;w<a[q];w++){
            z+=c[w];
        }
    }
    int r=0;
    string zt;
    zt=z;
    int s=0;
    if(z.size()%2==0){
        r=z.size()/2;
        for(int t=0;t<r/2;t++){
            z[t]=zt[r-t];
        }
    }
    else{
        r=z.size()/2;
        for(int t=0;t<r/2;t++){
            z[t]=zt[r-t];
        }
    }
    for(int a=0;a<r+1;a++){
        if(z[a]!=z[r]){
            cnt++;
        }
    }
    if(cnt>0){
    cnt++;
	}
	cout<<cnt;
    return 0;
}
