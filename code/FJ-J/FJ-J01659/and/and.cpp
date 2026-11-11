#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a[200001],b,c;
	cin>>b>>c;
	for(int i=0;i<b;i++){
		cin>>a[i];
	}
	sort(a,a+b);
	cout<<a[b-c];

	return 0;
} 
