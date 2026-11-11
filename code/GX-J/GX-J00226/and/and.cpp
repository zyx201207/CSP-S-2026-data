#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010],ans=INT_MIN;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==1){
	   for(int i=1;i<=n;i++)ans=max(ans,a[i]);
       cout<<ans;
	}
	if(m==2){
	   for(int i=1;i<=n;i++)
		   for(int j=i+1;j<=n;j++)
		       ans=max(ans,max(a[i]&a[j],a[j]&a[i]));
	   cout<<ans;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
