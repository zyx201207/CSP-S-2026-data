#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		int max_n=0;
		for(int i=0;i<n;i++){
			max_n=max(a[i],max_n);
		}
		cout<<max_n;
	}
	if(m==n){
		int count=a[0];
		for(int i=1;i<n;i++){
			count=count&&a[i];			
		}
		cout<<count;
	}
	return 0;
	
	
}
