#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	long long h[200001],l[2000];
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>h[i];
	}
	sort(h,h+a);
	int k;
	for(int i=a;i>b-1;i--){
		k=h[i-1];
		for(int j=0;j<b;j++){
			k=(k&h[i-j-1]);
		}
		l[i-1]=k;
	}
	sort(l,l+(a-b+1));
	cout<<l[a-1];
}
