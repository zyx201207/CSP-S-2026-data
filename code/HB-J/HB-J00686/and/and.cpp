#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],mx,b[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,k;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=30;j>=1;j--){
		int p=1<<j,ans=0;
		for(int i=1;i<=n;i++){
			if((a[i]&p)!=0) {ans++;}
		}
		if(ans>=m) {
			k=j;
			break;
		}
	}
	//cout<<k;
	for(int j=k;j>=0;j--){
		int p=1<<j,ans=0;
		for(int i=1;i<=n;i++){
			if((a[i]&p)!=0&&b[i]==0) ans++;
		}
		if(ans>=m){
			mx+=p;
			for(int i=1;i<=n;i++){
			    if((a[i]&p)==0){
					b[i]=1;
		        }
		    }
		}
	}
	cout<<mx;
}
