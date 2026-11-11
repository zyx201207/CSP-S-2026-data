#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[100005],b[100005],c=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	b[1]=a[1];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(b[i]<=a[j]){
				b[i]=a[j];
			}
		}
	}
	if(n%2==0){
		n=n/2;
		n+=1;
	}
	else{
		n=n/2;
		n+=2;
	}
	cout<<b[n];
	return 0;
}

