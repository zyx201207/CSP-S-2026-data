#include<bits/stdc++.h>
using namespace std;
int n,m,t,sum,l,ans;
int x[200010],a[200010],c[200010];
bool b[200010][40];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	if(m==1){
		int mx=0;
		for(int i=0;i<n;i++){
			if(a[i]>mx)mx=a[i];
		}
		cout<<mx<<endl;
	}
	for(int i=0;i<n;i++){
		t=0;
		while(a[i]>0){
			b[i][t]=a[i]%2;
			a[i]/=2;
			t++;
		}
	}
	for(int i=30;i>=0;i--){
		sum=0;
		for(int j=0;j<n;j++){
			if(b[j][i]){
				x[sum]=c[j];
				sum++;
			}
		}
		if(sum==m){
			ans=x[0];
			for(int j=1;j<m;j++)
				ans=ans&x[j];
		}
	}
	cout<<ans<<endl;
	return 0;
}
