#include<bits/stdc++.h>
using namespace std;
int M,N,a[200005];
bool cmp(int l,int r){
	return l>r;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	sort(a,a+N,cmp);
	cout<<a[M-1];
	return 0;
}
