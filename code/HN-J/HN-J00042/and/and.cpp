#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(const unsigned int &a,const unsigned int &b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	vector<unsigned int> a(n);
	for(unsigned int &i : a){
		cin>>i;
	}
	if(m==n){
		unsigned int sum = a[0];
		for(unsigned int &i : a){
			sum &= i;
		}
		cout<<sum;
	}
	else{
		sort(a.begin(),a.end(),cmp);
		unsigned int sum = a[0];
		for(unsigned int i=1;i<m;++i){
			sum = a[i];
		}
		cout<<sum;
	}
	return 0;
}
