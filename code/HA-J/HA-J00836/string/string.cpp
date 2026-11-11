#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,t=0,sum_=0,max_=0;
	cin>>n;
	vector<int>ve;
	vector<int>a(n);
	vector<string>c(n);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(a[i]>max_){
			max_=a[i];
			sum_++;
			if(a[i+1]>max_){
				max_=a[i+1];
				sum_++;
			}
			t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
		}
	}
	cout<<sum_;
	return 0;
}
