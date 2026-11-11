#include <bits/stdc++.h>
#include <vector>
using namespace std;
int n;
long long m;

static long long a[500005];

bool check(long long mi){
	for(int i=mi;i<n;i++){
		
	}
}
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	vector<int> an;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	bool flag=1;
	while(flag){
		flag=0;
		for(int i=0;i<n-1;i++){
			if(a[i]>a[i+1]){
				flag=1;
				int p=a[i];
				a[i]=a[i+1];
				a[i+1]=p;
			}
		}
	}
	cout<<"maopao"<<endl;
	long long v;
	long long x=1;
	for(int i=n-1;i>=0;i--){
		v=0;
		long long x2=0;
		for(int j=i;j>=0;j--){
			if(v+a[i]-a[j]>m){
				break;
			}
			v+=a[i]-a[j];
			x2++;
		}
		x=max(x,x2);
	}
	cout<<x;
	return 0;
}
