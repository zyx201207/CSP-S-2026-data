#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,s=0,d=0,g,cnt=0;
	cin>>n>>m;
	int a[n],b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>d){
			d=a[i];
		}
	}
	sort(a,a+n);
	while(d>0){
		for(int i=0;i<n;i++){
		b[i]=a[i];
	}
		g=m;
		for(int i=n;i>0;i--){
			while(g>0){
				if(b[i]<d && g!=0){
					b[i]++;
				}
				g--;
				}
			}
			for(int i=0;i<n;i++){
				if(b[i]==d){
					s++;
				}
			}
		if(s>cnt){
			cnt=s;
		}
		s=0;
		d--; 
	}
	cout<<cnt+2;
	return 0;
} 
