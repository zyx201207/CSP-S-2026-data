#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[500003];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long res=1,nn=a[0];
	while(1){
		nn++;m-=res;
		
		for(long long i=res;i<n;i++){
			if(a[i]==nn){
				res++;
			}else{
				break;
			}
		}
		if(m<0){
			cout<<res-1;return 0;
		}else if(m==0){
			cout<<res;return 0;
		}
	}
	return 0;
}
