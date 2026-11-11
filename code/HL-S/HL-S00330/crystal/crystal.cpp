#include<bits/stdc++.h>
using namespace std;
int f[100005];
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long sz=0;
	for(int i=1;i<=n;i++){
		cin>>f[i];
		sz+=f[i];
	}
	int d=(sz+m)/n;//Æ½¾ùÖµ 
	if(d*n==(sz+m)){
		cout<<n;
		return 0;
	}
	return 0;
}
