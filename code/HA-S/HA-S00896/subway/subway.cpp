#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	int n,m;
	cin>>n>>m;
	int cnt=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int j=n;n>0;n-=0){
		for(int i=0;i<n;i++){
			if(a[i]==a[i+1]){
			cnt++;
		}else{
				a[i]++;
				m--;
			}
		}
	}
	cout<<cnt;
	return 0;
}
