#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,v;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(m==1){
		cout<<a[n-1];
		return 0;
	}
	else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a[i]!=a[j])
					v=max(v,(a[i]&a[j]));
			}
		}
	}
	else if(m==3){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int z=0;z<n;z++){
					if(i!=j&&i!=z&&j!=z)
						v=max(v,(a[i]&a[j])&a[z]);
				}				
			}
		}
	}
	else if(m==4){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int z=0;z<n;z++){
					for(int f=0;f<n;f++){						
						if(i!=j&&i!=z&&i!=f&&j!=z&&j!=f&&z!=f)
							v=max(v,((a[i]&a[j])&a[z])&a[f]);
					}
				}				
			}
		}
	}
	else if(m==n){
		v=a[0];
		for(int i=1;i<n;i++){
			v=v&a[i];
		}
	}
	else if(m==n-1){		
		for(int i=1;i<n;i++){
			vv=a[i];
			for(int j=1;j<n;j++){
				 if(!(j==i))v=v&a[j];
			}
			v=max(v,vv);
		}
	}
	else if(a[n-1]<=4){
		v=a[n-1];
	}
	else{
		v=a[n-1];
		for(int i=m-1;i<n;i++){
			v=v&a[i];
		}
	}
	cout<<v;
	return 0;
} 
