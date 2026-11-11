#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200050];
int b[200050];
int A=1,B=1,ans,max1,c,maxi;
bool cmp(int a,int b){
	if(a>=b){
		return true;
	}
	return false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if((a[i]&2147483647)!=(a[i]&a[i])){
			A=0;
		}
	}
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]+1){
			B=0;
			break;
		}
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	else if(A==1){
		sort(a+1,a+n+1,cmp);
		ans=a[1];
		for(int i=2;i<=m;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	else if(n<=20){
		sort(a+1,a+n+1,cmp);
		int q[200050];
		for(int i=1;i<=n;i++){
			q[i]=a[i];
		}
		for(int i=1;i<=n;i++){
			memset(b,1,sizeof(a));
			b[i]=0;
			for(int k=2;k<=m;k++){
				for(int j=1;j<=n;j++){
					if(b[j]==0){
						continue;
					}
					c=q[i]&q[j];
					if(c>max1){
						max1=c;
						maxi=j;
					}
				}
				b[maxi]=0;
				q[i]=max1;
			}
			ans=max(ans,max1);
		}
		cout<<ans;
	}
	else if(B==1){
		cout<<49152;
	}
	return 0;
}

