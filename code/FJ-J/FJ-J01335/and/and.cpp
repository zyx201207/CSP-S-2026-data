#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[100000],s=0,d;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int f,g;
	for(int j=1;j<m;j++){		
		s=0;		
		f=0;
		for(int i=1;i<=n;i++){
			if(s<a[i]){
				s=a[i];
				d=i;
			}	
		}
		for(int i=1;i<=n;i++){
			if(i==d) continue;
			if(f<(s&a[i])){
				f=s&a[i];
				g=i;			
			}
		}
		a[d]=s;
		a[g]=0;		
	}	
	cout<<f;
	return 0;
}