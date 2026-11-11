#include<bits/stdc++.h> 
using namespace std;
long long n,a[1000005],c;
int main(){
	//freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			if(a[i]==a[j]&&c<a[i])c=a[i];
		}
	}
			

	cout<<c;
	
	return 0;
}
