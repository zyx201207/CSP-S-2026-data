#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a[200001];
	char c[200001];
	long long sum=0,n;
	cin>>n;
	int l=1,r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}while(true){

		if(l>=r){
			cout<<sum;
			break;
		}long long k=min(a[l],a[r]);
		if(c[l]==c[r]){
			a[l]-=k;
			a[r]-=k;
			if(a[l]==0)l++;
			if(a[r]==0)r--;

		}
		else{
			a[l]-=k;
			a[r]-=k;
			if(a[l]==0)l++;
			if(a[r]==0)r--;
			sum+=k;

		}
	}
	return 0;
}
