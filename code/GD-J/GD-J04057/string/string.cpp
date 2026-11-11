#include <bits/stdc++.h> 
using namespace std;
long long a[200005];
char b[200005];
int main(){
	long long n,cnt=0;
	cin>>n;
	int w;
	for(int i=1;i<=n;i++){
		char s;
		int x;
		cin>>x>>s;
		a[i]=x;	
		b[i]=s;
	}
	long long l=1,r=n;
	while(l<r){
		long long s=min(a[l],a[r]);
		if(b[l]==b[r]){
			a[l]-=s;
			a[r]-=s;
			if(a[l]==0) l++;
			if(a[r]==0) r--;
		}
		else if(b[l]!=b[r]){
			cnt+=s;
			a[l]-=s;
			a[r]-=s;
			if(a[l]==0) l++;
			if(a[r]==0) r--;
		}
		//cout<<cnt<<" "<<l<<" "<<r<<endl;
	}
	cout<<cnt;
	return 0;
}
