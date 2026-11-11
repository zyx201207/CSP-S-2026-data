#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,a;
	int best1=0,best2=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a>=best1){
			best2=best1;
			best1=a;
		}
		else if(a>=best2){
			best2=a;
		}
	}
	cout<<best2;
	return 0;
} 
