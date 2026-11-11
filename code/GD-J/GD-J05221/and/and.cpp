#include<bits/stdc++.h>
using namespace std;
int n,m,s,c,a[10000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				c=a[i]&a[j];
				s=max(s,c);
			}
		}
	}
	else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int x=j+1;x<=n;x++){
					c=a[i]&a[j]&a[x];
					s=max(s,c);
				}
			}
		}
	}
	cout<<s;
}
