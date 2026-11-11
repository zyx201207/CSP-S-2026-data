#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	long long ll[100000000];
	cin>>n>>m;
	
	
	for(long long i=0;i<n;i++){
		cin>>ll[i];
	}

	for(long long i=0;i<m;i++){
		cout<<ll[i]*3;
	}
	

	
	
	
	
	return 0;
}
