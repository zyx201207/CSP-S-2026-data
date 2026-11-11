#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;){	
		long long x;
		char tmp;
		cin>>x>>tmp;
		if(tmp==c[i-1]){
			a[i-1]+=x;
			n--;
		}
		else{
			a[i]=x;
			c[i]=tmp;
			i++;
		}
	}
	/*
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	for(int i=1;i<=n;i++){
		cout<<c[i]<<" ";
	}
	*/
//	cout<<a[1]<<" "<<c[1]<<"\n";
	int l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){
			long long tmp=min(a[l],a[r]);
			a[l]-=tmp;
			a[r]-=tmp;
			if(a[l]==0){
				l++;
			}
			if(a[r]==0){
				r--;
			}
		}
		else{
			long long tmp=min(a[l],a[r]);
			a[l]-=tmp;
			a[r]-=tmp;
			ans+=tmp;
			if(a[l]==0){
				l++;
			}
			if(a[r]==0){
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
