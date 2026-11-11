#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5;
int n,ans=0,m;
int a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			if(m-(a[i]-a[j])>=0){
				m-=(a[i]-a[j]);
				a[j]=a[i];
			}
		}
		if(m<=0){
				break;
			}
 }
 int o=a[1];
	for(int i=1;i<n;i++){
		if(a[i]==o){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
