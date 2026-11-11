#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		int yyds=a[0];
		for(int i=1;i<n;i++){
			if(a[i]>yyds){
				yyds = a[i];
			}
		}
		cout<<yyds;
		return 0;
	}else{
		int x=0;
		for(int i=0;i<m;i++){
			x=x&a[i];
		}
		cout<<x;
	}
	return 0;
}
