#include <bits/stdc++.h>
using namespace std;

int l[200001];
int n,m,s=0;

void f(int a,int b,int r){
	if(a<=0){
		if(r>s){
			s=r;
		}
	}
	else{
		for(int i=b;i<=n-a;i++){
			if(r==-1){
				f(a-1,i+1,l[i]);
				
			}
			else{
				f(a-1,i+1,r&l[i]);
			}
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	f(m,0,-1);
	cout<<s;
	return 0;
}
