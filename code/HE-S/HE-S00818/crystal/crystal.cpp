#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n,com=0;
	cin>>m>>n;
	int a[n];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=m;j++){
		if(i=m){
		com++;
	}
		}
	}
	cout<<com<<endl;
	return 0;
}
