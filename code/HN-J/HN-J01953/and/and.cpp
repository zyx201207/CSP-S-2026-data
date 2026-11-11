#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,x;
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	int q;
	for(int i=1;i<=x;i++){
		int k=0,u;
		for(int j=1;j<=n;j++){
			if(a[j]>k){
				k=a[j];
				u=j;
			}
		}
		a[u]=0;
		if(i==1)q=k;
		else q=q&k;
	}
	cout<<q;
	return 0;
} 
