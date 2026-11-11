#include<bits/stdc++.h>
using namespace std;
int n,m,a;
vector <long long> lht;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a;
		lht.push_back(a);
	}
	sort(lht.begin(),lht.end(),cmp);
	cout<<lht[m-1];
	return 0;
}
