#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,max=0;
	cin>>n>>m;
	long long number;
	for(int i=1;i<=n;i++){
		cin>>number;
		if(number>max){
			max=number;
		}
	}
	cout<<max;
	
	
	
	return 0;
}
