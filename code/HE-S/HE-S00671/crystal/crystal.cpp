#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,b=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		while(a[i]!=a[i+1]){
			a[i]++;
			m--;
		}
		if(m==0){
			break;
		}
	}
	for(int i=0;i<n;i++){
		b++;
		if(a[i]!=a[i+1]){
			break;
		}
	}
	cout<<b;
	return 0;
}
