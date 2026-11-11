#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,index=0;
	cin>>n>>m;
	int num[m];
	for(int i=0;i<m;i++){
		cin>>num[i];
	}
	if(n==1){
		sort(num,num+m);
		cout<<num[m-1];
	}
	return 0;	
}
