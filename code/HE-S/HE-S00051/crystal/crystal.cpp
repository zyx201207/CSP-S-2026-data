#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[500005]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int js=1,js2=0,l=0;
	int max=a[js];
	for(int i=0;i<m;i++){
		max=a[js];
		if(a[js-1]<max){
			a[js-1]++;
			l++;
		}
		else{
			a[js]*=2;
			a[js-1]*=2;
			js++;
			js2++;;
		}
	}
	cout<<abs(js2-l);
	return 0;
} 
