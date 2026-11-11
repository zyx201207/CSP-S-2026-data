#include<bits/stdc++.h>
using namespace std;
int n,m,a[200150],ans;
bool cap(int a,int b){
	int xa,xb;
	xa=0;xb=0;
	if(!a){
		return 0;
	}
	if(!b){
		return 1;
	}
	while(a){
		if(a%2==1){
			xa++;
		}
		a/=2;
	}
	while(b){
		if(b%2==1){
			xb++;
		}
		b/=2;
	}
	return xa>xb;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cap);
	ans=a[0];
	for(int i=0;i<m;i++){
		//cout<<a[i]<<endl;
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
