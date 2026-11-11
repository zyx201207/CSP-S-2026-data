#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	cin>>n>>m;
	int f=1,f1=1;
	long long maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		if(a[i]!=0){
			f=0;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1){
			f1=0;
			break;
		}
	}
	if(f==1){
		cout<<0;
	}
	else if(f1==1){
		cout<<maxx;
	}
	else{
		cout<<3;
	}
	return 0;
}
