#include<bits/stdc++.h> 
using namespace std;
int n,m;
int a[100000];
long flag=1,k=0,c=1,ans=-10000;
long a1[100000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=m-1){
			int t=a[i];
			a1[i]=max(ans,long (a[i-1] and t));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans=max(ans,long(a[i] and a1[j]));
		}
		
	}
	cout<<ans;
	return 0;
}
 /*5 3
 31 3 1 15 7*/
/*4 2
  3 15 12 12*/
