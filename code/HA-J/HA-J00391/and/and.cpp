#include<bits/stdc++.h>
bool cmp(int x,int y){
	return x>y;
}
using namespace std;

int n,m,a[200009];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	int s=a[0];
	for(int i=1;i<m;i++){
		s=s&a[i];
	}
	cout<<s;
	return 0;
}
