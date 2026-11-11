#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200050],sum;
char c[200050];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];	
	}
	int l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]){
			sum+=min(a[l],a[r]);
		}
		long long p=min(a[l],a[r]);
		a[l]-=p;
		a[r]-=p;
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
//		for(int i=l;i<=r;i++){
//			cout<<c[i]<<" ";
//		} 
//		cout<<endl;
//		for(int i=l;i<=r;i++){
//			cout<<a[i]<<" ";
//		} 
//		cout<<endl;
		
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
