#include<bits/stdc++.h>
using namespace std;
vector<int> w;
int main(){
	("and.in",stdin);
	("and.out",stdout);
	int n,m;
	cin>>n>>m;
	while(n--){
		int a;
		cin>>a;
		w.push_back(a);
	}
	int s=1,s2=1;
	for(int i=n-m+1;i<=n;i++) s*=i;
	for(int i=1;i<=m;i++) s2*=i;
	int s3=s/s2;
	int sum=w[0],maxx=0;
	while(s3--){
		for(int i=1;i<n;i++){
			for(int j=i;j<=m+i;j++){
				sum=(sum & w[j]);
			}
			maxx=max(maxx,sum);
		}
	}
	cout<<maxx;
	return 0;
}
