#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> shu;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		shu.push_back(a);
	}
	sort(shu.begin(),shu.end(),cmp);
	
	int a=shu.size(),b=0;
	int l[a];
	for(int i:shu){
		l[b]=i;
		b++;
	}
	cout<<l[1];
	return 0;
}
