#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
int main(){
//  freopen("migrate.in","r",stdin);
//  freopen("migrate.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int C,T;
  cin>>C>>T;
    long long ans=0;
    while(T--){
      int n;
      long long d;
      cin>>n>>d;
      for(int i=1;i<=n;i++){
        cin>>a[i];
      }
      sort(a+1,a+n+1);
      for(int l=1;l<=n;l++){
        for(int r=l+3;r<=n;r++){
          int flag=0;
          for(int i=l;i<=r;i++){
		    if(i+1<=r&&a[i+1]-a[i]>d){
              flag=0;
              break;
            }
		    else if(i+2<=r&&a[i+1]-a[i]<=d&&a[i+2]-a[i]<=d){
			  if(i+3<=r&&a[i+3]-a[i+1]<=d){
				flag=0;
				break;
			  }
			  else if(i+3>r||(i+3<=r&&flag==0&&a[i+3]-a[i+1]>d))flag=1;
			  else if(i+3<=r&&flag==2&&a[i+3]-a[i+1]>d){
			    flag=0;
			    break;
			  }
			}
		  }
		  if(flag==1)ans++;
        }
      }
      cout<<ans<<endl;
      ans=0;
    }
  return 0;
}
