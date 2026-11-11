#include<bits/stdc++.h>
using namespace std;
int a[200005]={0};
int c[1000000]={0};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int k=0;
	bool f=true;
	bool ff=false;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=4){
			f=false;
			k=i;
		}
		//if(a[i]%2==0)ff=true;
		c[a[i]]++;
		if(c[a[i]]>=m){
			cout<<a[i]<<endl;
			return 0;
		}
	}
	if(f){
		//sort(a+1,a+n+1);
		//cout<<a[n-m+1]<<endl;
		if(c[3]>=m)cout<<3<<endl;
		else if(c[3]+c[2]>=m)cout<<2<<endl;
		else if(c[3]+c[1]>=m)cout<<1<<endl;
		else cout<<0<<endl;
	}else{
		sort(a+1,a+n+1);
		cout<<a[n-m+1]<<endl;
	}
	
	
	
	
	return 0;
}

