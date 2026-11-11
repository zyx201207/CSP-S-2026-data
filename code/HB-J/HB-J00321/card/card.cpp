#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],t[100005],ans[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool f=true;
	int x=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(x>a[i]){
			f=false;
		}
		x=a[i];
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(f){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]){
				cout<<i<<' ';
			}
		}
		return 0;
	}
	if(m==2){
		if(a[n]==1){
			cout<<n<<' ';
			int sum=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					if(sum==1){
						cout<<i-1;
						return 0;
					}
					else{
						sum++;
					}
				}
			}
		}
		else{
			int sum=0;
			for(int i=1;i<=n;i++){
				if(a[i]==2){
					if(sum==1){
						cout<<i-1;
					}
					else{
						sum++;
					}
				}
			}
			cout<<' '<<n;
		}
	}
	for(int i=1;i<=n;i++){
		memset(t,0,sizeof(t));
		for(int j=1;j<=n-i+1;j++){
			t[j]=a[i+j-1];
			for(int k=1;k<=j;k++){
				if(t[k]==t[j]){
					for(int l=k;l<=j-1;l++){
						t[l]=0;
					}
				}
			}
		}
		for(int j=1;j<=n-i+1;j++){
			ans[t[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
