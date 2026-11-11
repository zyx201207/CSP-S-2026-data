#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[100100],mx=-1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}sort(a,a+n,cmp);
	if(m==1){
		cout<<a[0];
	}else if(m==2){
		for(int i=1;i<n;i++){
			mx=max(mx,a[0]&a[i]);
		}cout<<mx;
	}else{
		int mj=max(a[0]&a[1],max(a[1]&a[2],a[2]&a[3]));
		cout<<mj;
	}
	return 0;
}
