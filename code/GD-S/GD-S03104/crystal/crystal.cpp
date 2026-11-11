#include<bits/stdc++.h>
using namespace std;
const int M=8*1e5+10;
int n,m,a[M],sum=1,b[M],c[M],g;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int t=m;
	int ans[n+10];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i == j) continue;
			if(a[i]>=b[j]){
				c[j]= a[i] - b[j];
				g++;
			}
			else break;
		//	cout<<c[j]<<" ";
		}
		//cout<<endl;
		
		sort(c+1,c+1+g);
		int kk=1;
		for(int o=1;o<=g;o++){
			if(t-c[o]>=0) sum++,t-=c[o];
			else break;
			//cout<<t<<" ";
		}
		//cout<<sum<<endl;
		ans[i] = sum;
		//cout<<ans[i]<<" ";
		t=m;
		sum=1;
		g=0;
	}
	sort(ans+1,ans+1+n);
	cout<<ans[n];
	return 0;
}
