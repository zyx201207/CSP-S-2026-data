#include<bits/stdc++.h>
using namespace std;
int n,m,maxa=0;
int a[200007];
//int andd(int s,int x,int y,int k){
//	if(k==0)return s;
//	for(int i=0;i<)
//	
//}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
//	andd(a[0]&a[1],a[0],a[1],m);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j&&a[i]&a[j]>=maxa){
				maxa=a[i]&a[j];
			}
		}
	}
	cout<<maxa;
	return 0;
}
