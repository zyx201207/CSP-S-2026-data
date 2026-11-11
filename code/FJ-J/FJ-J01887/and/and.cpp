#include <bits/stdc++.h>
using namespace std;

int n,m,a[200005],sum,t;
bool flag = 0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(int i=0;i<m;i++){
		sum = a[0];
		t = sum;
	}
	if(m==1){
		flag = 1;
	}
	for(int i=0;i<m;i++){
		sum = sum & a[i];
	}
	if(flag == 1){
		cout<<t;
	}
	else{
		cout<<sum;
	}
	return 0;
}
