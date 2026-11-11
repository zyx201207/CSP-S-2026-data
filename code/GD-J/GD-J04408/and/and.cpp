#include<iostream>
using namespace std;
int main(){
	int n,m;int mu = 0;
	cin>>n>>m;
	int a[n];
	for(int i = 0;i<n;i++){
		cin>>a[i];mu=a[i];
		if(i!=0&&a[i]>mu&&(a[i]<mu+12||a[i]>mu+32))mu==a[i];
	}
	cout<<mu;
	return 0;
}

