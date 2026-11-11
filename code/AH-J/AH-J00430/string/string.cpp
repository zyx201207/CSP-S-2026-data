#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,s=0;
	long long a[200005];
	char b[200005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int i=1,j=n;
	while(i<j){
		if(b[i]==b[j]){
			long long k=min(a[i],a[j]);
			a[i]-=k;
			a[j]-=k;
		}else{
			s+=min(a[i],a[j]);
			long long k=min(a[i],a[j]);
			a[i]-=k;
			a[j]-=k;
			
		}
		if(a[i]==0){
			i++;
		}
		if(a[j]==0){
			j--;
		}
	}
	cout<<s;
	return 0;
}
