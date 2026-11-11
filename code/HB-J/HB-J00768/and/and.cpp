#include<bits/stdc++.h>
using namespace std;
int a[200100],n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxa=0,ans=0,cl=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxa=max(maxa,a[i]);
	}
	for(int i=ceil(log2(maxa))-1;i>=0;i--){
		int check=0;
		for(int j=1;j<=n;j++){
			if(((a[j]>>i)%2)==1){
				check++;
			}
			if(check>=m){
				break;
			}
		}
		if(check>=m){
			ans+=(1<<i);
			cl=1;
		}
		for(int j=1;j<=n;j++){
			if(((a[j]>>i)%2)==0&&cl==1){
				a[j]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
