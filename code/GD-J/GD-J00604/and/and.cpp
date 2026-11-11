#include<bits/stdc++.h>
using namespace std;

int n;
int a[100000000];
int land(int i){
	return rand()%i;
}

int main(){

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	int mx=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	srand(time(0));
	cout<<land(mx);

	return 0;
}

