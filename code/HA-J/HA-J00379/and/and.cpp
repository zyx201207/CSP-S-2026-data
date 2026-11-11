#include<bits/stdc++.h>
using namespace std;
long long ns[200000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>ns[i];
	}sort(ns,ns+n,cmp);
	cout<<ns[m-1]<<endl;
	return 0;
} 
