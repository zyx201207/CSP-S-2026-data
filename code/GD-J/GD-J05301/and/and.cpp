#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200001];
	cin>>n>>m;
	long long max_=0,l;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>max_){
			max_=a[i];
			l=i;
		}
	}
	m--;
	while(m--){
		a[l]=0;
		max_=0;
		for(int i=1;i<=n;i++){
			if(a[i]>max_){
				max_=a[i];
				l=i;
			}
		}
	}
	cout<<max_<<endl;
	return 0;
}
