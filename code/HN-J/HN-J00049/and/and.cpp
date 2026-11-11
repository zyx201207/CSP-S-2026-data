#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("and.in","r","stdin");
	freopen("and.out","w","stdout")
	int n, m,a[100000],cnt=0;
	cin>>n>>m;
	for (int i=0;i<n;i++){
		 cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=0;i<n-1;i++){
		if(a[i+1]!=a[i]){
			cnt=a[i];
		}
	}
	cout<<cnt;
	return 0;
}
