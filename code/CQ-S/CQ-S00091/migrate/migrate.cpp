#include<bits/stdc++.h>
using namespace std;

int c,t,ans[10005],num;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int n,d,a[200010]={0};
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>a[i];
		}
		if(n<d)
			continue;
		for(int j=1;j<n;j++){
			num+=a[j]-a[j-1];
			if(a[j]-a[j-1]>d){
				break;
			}
		}
		if(num<2*d)
			ans[i]=0;
		else
			ans[i]=num/2/d+num-2*d;
	}
	for(int i=0;i<t;i++){
		cout<<ans[i];
	}
	return 0;
}
