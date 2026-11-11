#include <bits/stdc++.h>
using namespace std;int n;
long long m;
long long a[500005];

int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];

}
sort(a+1,a+n+1);
int u=m;
int y=0;
int c=0;
int h=0;
int j=0;

for(int i=a[n];i>=a[1];i--){
        for(j=n;j>=1;j--){
            if(i>=a[j]&&i<=a[j+1]){
                h=j;break;


            }
            if(i>=a[j]&&i==a[n]){
                h=j;break;


            }

        }
        m=u;
        y=0;

    while(m>=0&&h>=1){
        m-=(i-a[h]);
        if(m>=0){y++;}
        h--;


    }

    c=max(c,y);

}
cout<<c;
return 0;
}
