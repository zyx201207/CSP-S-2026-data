#include<iostream>
#include<vector>
using namespace std;
int n,m;
int a[200009];
vector<int> x;
int maxa;int maxp;int tmp;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin	>>n >> m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	maxa=a[0];
	for(int j=0;j<m;j++){
	for(int i=0;i<n;i++){
		maxa=max(maxa,a[i]);
		if(tmp!=maxa)maxp=i;
		tmp=maxa;
	}
	a[maxp]=0;
	x.push_back(maxa);
	}
	cout<<x[m-1];
}
