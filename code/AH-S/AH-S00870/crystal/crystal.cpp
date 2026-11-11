#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],sum=0,b;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
	}
    for(int i=1;i<=n;i++){
		int ans=n/2+1;
        sum++;
        if(a[i]<=a[i+1]){
           if(i<=ans){
              break;
              ++i;
              for(int j=n;j>=0;j--){
                  a[j]=a[j]+b;
                  a[j-1]=a[j-1]+(m-b);
                  if(a[j]==a[ans]){
                     sum++;
                  }
               }
           }
	   }
	}
    cout<<sum+2<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

