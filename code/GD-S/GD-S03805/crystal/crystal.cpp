#include <bits/stdc++.h>
using namespace std;
const int N=1e8;__int64 m,n;
long long a[N];

int main (){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long sum=0;
	bool is_A=1,is_B=1;long long minx=-1e9;
	
	cin>>n>>m;
	
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			is_A=0;
		}
	}
	
	int s=abs(a[2]-a[1]);
	if(is_A==0){
		
		for(long long i=3;i<=n;i++){
			if(abs(a[i]-a[i-1])!=s){
				is_B=0;
			}
		}

	}
	

	if(is_A){
		if(n%2==0){
			long long mid=a[n/2];
		}
		else{
			long long mid=a[(n+1)/2];
		}
		long long i=1;
		
		while(m!=0){
			if(m-i>=0){
				m-=i;sum++;
				cout<<sum;
				i++;
			}
			else{
				break;
			}
		}
		
	}
	
	if(is_B){
		sum=m/s;
	}
	
	cout<<sum+1;
	

	
	

	return 0;
}






 
