#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans=INT_MAX;
bool cmp(int a,int b){
	return a<b;
}
int main(){	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	cout<<a[0];
	return 0;
} 	
