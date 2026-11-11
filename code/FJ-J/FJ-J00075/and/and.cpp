#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[200005],b[100];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int p=log(a[i])/log(2);
		for(int j=0;j<=p;j++){
			b[j]++;
		}
	}
	int c=100;
	while(b[c]<m){
		c--;
	}
	for(int i=0;i<n;i++){
		while(1){
			int j=log(a[i])/log(2),k=int(pow(2,j));
			if(j<=c){
				break;
			}
			a[i]-=k;
		}
	}
	sort(a,a+n);
	ans=a[n-1];
	for(int i=n-1;i>=n-m;i--){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
