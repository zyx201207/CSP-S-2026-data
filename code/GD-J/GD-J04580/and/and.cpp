#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],p=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>p){
			p=a[i];
		}
	}
	int x=a[0],check=0,ans=0;
	for(int i=0;i<n;i++){
		if(a[i]!=x)
			check++;
		if(a[i]==p)
			ans++;
	}
	if(!check){
		cout<<x;
		return 0;
	}
	if(ans>=m){
		cout<<p;
		return 0;
	}
}
