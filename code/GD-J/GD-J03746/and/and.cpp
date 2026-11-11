#include<bits/stdc++.h>
using namespace std;
int n,m,s,g,r,a[1000000],b[1000000];
void p(int k){
	for(int i=1;i<=n;i++){
		if(k==1){
			s=a[i];
		}
		if(b[i]==0){
			b[i]=1;
			g=s;
			s=s&a[i];
			if(k==m){
				if(s>=r){
					r=s;
				}
			}
			else{
			p(k+1);
			}
			b[i]=0;
			s=g;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	p(1);
	cout<<r;
}
