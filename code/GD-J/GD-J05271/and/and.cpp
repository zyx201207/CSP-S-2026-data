#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[100000010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long mx=-1;
	for(int i=1;i<=n;i++){
		int s=0;
		for(int j=i+1;j<=i+m-1;j++){
			s+=a[i]&a[j];
		}
		if(s>mx){
			mx=s;
		}
	}
	cout<<mx;
	return 0;
} 
