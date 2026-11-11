#include<bits/stdc++.h>
using namespace std;
int a[200005];
char ans[1000000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,d=0,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ans[sum];
		for(int j=1;j<=a[i]-1;j++){
			sum++;
			ans[sum]=ans[sum-1];
		}
		if(i!=n)sum++;
	}
	for(int i=0;i<=sum/2;i++){
		if(ans[i]!=ans[sum-i]){
		    d++;	
		}
	}
	cout<<d;
	return 0;
}
