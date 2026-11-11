#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
   	int n;
	cin>>n;
	long long a[n+5];
	long long ans=0,m;
	cin>>m;
	cin>>a[1]>>a[2];
	  for(int i=3;i<=n;i++){
    	cin>>a[i];
      }
      sort(a+1,a+n+1);
      int sum=1;
    for(int i=n;i>=sum;i--){
    	long long ans1=0,js=1; long long m1=m;
    	for(int j=i-1;j>=1;j--){
    		ans1+=a[i]-a[j];
    		if(m1>=ans1){
    			js++;
    		}else{
    			break;
    		}
    	}
    	ans=max(ans,js);
    	sum=ans;
    }
    cout<<ans;
    return 0;
}
