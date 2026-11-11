#include<bits/stdc++.h>
using namespace std;
bool compare(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>xl(n);
	for(int i=0;i<n;i++){
		cin>>xl[i];
	}
	sort(xl.begin(),xl.end(),compare);
	for(int i=0;i<1;i++){
		cout<<xl[i];
	}
	return 0;
}
