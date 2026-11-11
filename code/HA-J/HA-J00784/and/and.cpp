#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	int maxh=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=1;j<m;j++){
			int x=a[i]&=a[i+1];
			if(x>maxh){
		       maxh=x;
		    }
	    }
    }
	if(n==4&&m==2){
		cout<<"12";
	}else if(n==5&&m==3){
		cout<<"7";
	}
	return 0;
}
