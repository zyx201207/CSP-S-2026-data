#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[100001],b[10000001],sum=0,t=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		b[1]=a[1];
		for(int i=2;i<=n;i++){
			if(b[1]<a[i]){
				b[1]=a[i];
			}
		}
		cout<<b[1];
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;i<=n;j++){
				b[t]=a[i]&a[j];
				t++;
			}
		}
		sum=b[1];
		for(int i=2;i<=t;i++){
			if(sum<b[i]){
				sum=b[i];
			}
		}
		cout<<sum;
	}else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;i<=n;j++){
				for(int k=j+1;k<=n;k++){
					b[t]=a[i]&a[j]&a[k];
					t++;
				}
			}
		}
		sum=b[1];
		for(int i=2;i<=n;i++){
			if(sum<b[i]){
				sum=b[i];
			}
		}
		cout<<sum;
	}else{
		for(int i=1;i<=m;i++){
			cout<<a[i];
		}
	}
	return 0;
}
