#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int cnt=0,w=0,max=0,n,m,a[1001],c[1001];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		c[i]=a[i]; 
	}
	int r=0,b=m;
	while(1){
		b=m;
		w=a[r];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(c[i]<a[r]){
					c[i]+=1;
					b--;
				}	
			}
		}
		for(int i=0;i<n;i++){
			if(c[i]==w) cnt++;
		}
		if(cnt>=max){
			max=cnt;
		}
		if(r==n) break;
		r++;
	}
	cout<<max;
	return 0;
}
