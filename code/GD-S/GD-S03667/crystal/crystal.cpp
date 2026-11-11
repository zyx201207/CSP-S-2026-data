#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,s=0,m1;
	cin>>n>>m;
	m1=m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=1;a[i]<=a[i-1];j++){
			a[i]++;
			m--;
		}
		if(m*2>=a[i-2]-a[i]){
			for(int j=1;a[i]<=a[i-2];j++){
				a[i]++;
				a[i-1]++;
				m-=2;
			}
		}
	}
	for(int i=1;i<n;i++){
		if(a[i]==a[i-1]){
			s++;
		}
	}
	cout<<s<<endl;
	return 0;
}
