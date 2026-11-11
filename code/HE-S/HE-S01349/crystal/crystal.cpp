#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int i=0;
	while(1){
		if(a[i]<a[i+1]){
			a[i]++;
			m--;
		}else if(a[i+1]<a[i+2]){
			a[i]++;
			a[i+1]++;
			m-=2;
		}else if(m==0){
			break;
		}
		if(a[i+1]==a[i+2] && m>0) i++;
	}
	int h=1;
	for(int i=0;i<n;i++){
		if(a[i]==a[i+1]){
			h++;
		}
	}
	cout<<h;
	return 0;
}
