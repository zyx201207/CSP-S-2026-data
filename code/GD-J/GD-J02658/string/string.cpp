#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct node{
	long long m;
	char x;
}a[200010];
int main(){ 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].x;
	}
	int l=1,r=n;
	long long sum=0;
	while(l<=r){
		sum+=a[r].m;
		if(a[r].x!=a[l].x){
			ans+=min(a[r].m,a[l].m-(sum-a[r].m));
		}
		if(sum>=a[l].m){
			if(sum>a[l].m) a[r].m=sum-a[l].m;
			else r--;
			l++;
			sum=0;
		}else{
			r--;
		}
	}
	cout<<ans;
	return 0;
} 
