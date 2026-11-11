#include<bits/stdc++.h>
using namespace std;
const int N_=2e5+10;
int n_,m_,a_[N_];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n_>>m_;
	for(int i=1;i<=n_;i++){
		cin>>a_[i];
	}
	sort(a_+1,a_+n_+1);
	int max_sum=-1;
	
	for(int i=n_;i>=1;i--){
		int d_=a_[i];
		for(int j=i-1;j>=i-m_+1 and i-m_+1>=1;j--){
			d_=d_&a_[j];
		}
		max_sum=max(max_sum,d_);
	}
	cout<<max_sum;
	return 0;
} 
