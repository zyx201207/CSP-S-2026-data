#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int m;
	cin>>n;
	cin>>m;
	int a[100];
	int q;
	for(int i=1;i<=n;i++){
		cin>>q;
		a[q]++;
	} 
	int s=2;
	for(int i=1;i<=n;i++){
		if(a[i]>0){
			cout<<n;
			s--;
		}else{
			cout<<0;
		}
		if(s==0){
			break;
		}
	} 
	return 0;
} 
