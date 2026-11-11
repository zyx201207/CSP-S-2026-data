#include<bits/stdc++.h>
using namespace std;
int n,m,max=0;//and
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==m){
		max=a[0];
		for(int i=1;i<n;i++){
			max=max and a[i];
		}
		cout<<max;
	}else if(m==1){
		sort(a,a+n,cmp);
		cout<<a[0];
	}else{
		cout<<a[n-2];
	}
	return 0
};

