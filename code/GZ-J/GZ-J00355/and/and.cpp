//GZ-J00355 ¶Å¾´Ðù
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,num=0;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int k=a[i];
		for(int j=0;j<n;j++){
			if(k & a[j]>num){
				num=k & a[j];
			}
		}
	}
	cout<<num; 
}
