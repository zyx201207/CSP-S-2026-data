#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travle.in","w",stdin);
	freopen("travel.out","r",stdout);
	int sum=0;
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int i=0;i<n;i++){
			if(a[i]==m)sum++;
		}
	}
	cout<<sum;
	return 0;
}
