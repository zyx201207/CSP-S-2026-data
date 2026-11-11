#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],k=1,b[200005],sum=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int jj=0;
	while(m--){
		int mx=INT_MIN,j=0;
		for(int i=jj+1;i<=n;i++){
			if(a[i]>mx){
				mx=a[i];
				j=i;
			}
		}
		b[k]=mx;
		a[j]=INT_MIN;
		k++;
		jj=j;
	}
	int sum=b[1];
	for(int i=2;i<k;i++){
		if(b[i]%sum==0&&(b[i]/sum)%2==0){
			sum=0;
		}else{
			sum=min(sum,b[i]);
		}
	}
	cout<<sum;
	return 0;
}
