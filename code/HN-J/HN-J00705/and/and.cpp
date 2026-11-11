#include<bits/stdc++.h>
using namespace std;
const int N=2e5+2; 
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cout.tie(0);
	cin.tie(0);
	ios::sync_with_stdio(false);
	long long n,m;
	cin>>n>>m;
	long long a[N];
	vector<bool> b;
	b.assign(n,false);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sumand=0;
	for(int i=1;i<=m;i++){
		long long maxw=0,maxi=0;
		for(int j=1;j<=n;j++){
			if(maxw<a[j]&&!b[j]){
				maxw=a[j];
				maxi=j;
			} 
		}
		if(i==1) sumand=maxw;
		else sumand=sumand&maxw;
		b[maxi]=true;
	}
	cout<<sumand<<endl;
	return 0;
}
