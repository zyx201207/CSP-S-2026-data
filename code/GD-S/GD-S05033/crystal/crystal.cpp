#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
     return a<b;
} 
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n+10],b[n+10];
	for(int i=1;i<=n;i++){
	   cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	long long num;
	if(n%2==0){
	   num=n/2;
    }else{
       num=n/2+1;
    }
    for(int i=1;i<=num;i++){
       b[i]=a[num]-a[i];
    }
    for(int i=num;i<=n;i++){
       b[i]=a[i]-a[num];
    }
	sort(b+1,b+1+n,cmp);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(b[i]<=m){
           ans++;
           m-=b[i];
       }else{
           break;
       }
    }
    cout<<ans;
    return 0;
}
 
