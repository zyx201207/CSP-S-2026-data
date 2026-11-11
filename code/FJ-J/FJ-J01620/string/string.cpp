#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a;
	long long r=0;
	int n;
	cin>>n;
	for(int j=1;j<=n;j++){
		//cout<<1;
		int w;
		string q;
		cin>>w>>q;
		//cout<<q;
		for(int i=r;i<=w+r-1;i++){
			a+=q;
		}
		r+=w;
		//cout<<a;
	}
	//cout<<a;
	r=0;
	long long ans=0,l=a.size();
	while(r<=(l/2)){
		//cout<<1;
		if(a[r]!=a[a.size()-r-1]) ans++;
		r++; 
	}
	cout<<ans;
	return 0;
} 
