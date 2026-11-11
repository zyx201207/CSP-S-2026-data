#include<bits/stdc++.h>
using namespace std;
long long n,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	long long q[n+5],y[n+5];
	for(int i=1;i<=n;i++){
		char z;
		cin>>q[i]>>z;
		y[i]=z-'a';
	}
	for(int i=1;i<=n/2;i++){
		long long r=n+1-i;
		while(q[r]==0){
			r--;
		}
		if(y[i]!=y[r]){
			if(q[i]>=q[r]&&y[i]!=y[r-1]){
				sum+=q[i];
				q[i]-=q[r];
				for(int j=r;j>=1;j--){
					if(q[i]>q[j]) q[j]==0;
					else q[j]-=q[i];
					if(q[i]-q[j]>0) q[i]-=q[j];
					if(q[i]==0) break;
				}
			} 
			else sum+=q[r];
		}
	}
	cout<<sum;
	return 0;
}
