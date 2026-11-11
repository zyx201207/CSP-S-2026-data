#include<bits/stdc++.h>
using namespace std;
const long long MAXN=500001;
long long n,m;
int a[MAXN];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
		    if(a[i]<a[j]){
		    	swap(a[i],a[j]);
			}
	    }
	}
	int max=0;
	for(int i=1;i<=n;i++){
		int s=0;
	    for(int j=1;j<=i;j++){
	    	s+=a[i]-a[j];
		}
		if(s<=m&&i>max){
			max=i;
		}
	}
	cout<<max;
	return 0;
}
