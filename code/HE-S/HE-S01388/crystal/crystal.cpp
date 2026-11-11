#include<iostream>
using namespace std;
void swap( int a , int b){
	int c=a;
	a=b;
	b=c;	
	}
	void shuchu(int a){	
		freopen("crystal.out","w",stdout);
		cout<<a;
	}
int main(){
	freopen("crystal.in","r",stdin);
	int n,m,sum=0,t;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			if(a[j]>=a[j+1]){
			swap(a[j],a[j+1]);	
			}
		}
	}
			for(int i=0;i<m;i++){
		if(a[i]<a[i+1]){
			for(int j=0;j<i;j++){
				a[j]+=1;
				sum+=1;
				m--;
			}
		}
}
		shuchu(sum);
		return 0;
}
