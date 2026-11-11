#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
		long long max=0,n=0,m=0,a[10000000]={0};
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	long long i=0,j=0,v[10000000]={0};
	if(n==m){
		max=a[0];
		for(;i<n;i++){
			max=max&a[i];
		}
		cout<<max;
		return 0;
	}
		if(m==2){
		max=a[0]&a[1];
		for(;i<n;i++){
			for(j=i+1;j<n;j++){
				if(max<a[i]&a[j])
				max=a[i]&a[j];
			}
			
		}
		cout<<max;
		return 0;
	}
	
	
		if(m==3){
		max=a[i]&a[i+1]&a[i+2];
		for(;v[0]<n;v[0]++){
			for(v[1]=v[0];v[1]<n;v[1]++){
				for(v[2]=v[1];v[2]<n;v[2]++){
				
				if(max<a[v[0]]&a[v[1]]&a[v[2]])
				max=a[v[0]]&a[v[1]]&a[v[2]];
			}
			
			}
			
		}
		cout<<max;
		return 0;
	}
		if(m==n-1){
			v[i]=a[i];
		for(;i<n;i++){
			for(;j<n;j++){
				
				if(i=j){
					if(j==0){
						v[i]=a[1];
					}
					continue;
				}
				else{
					if(j==0){
						v[i]=a[0];
					}
				}
				v[i]=v[i]&a[j];	
			}
			if(i==0){
				max=v[i];
			}
			
				if(max<v[i])
				max=v[i];
		}
			
		
		cout<<max;
		return 0;
	}
	
	cout<<a[3];
	
	
	
	
	
	//1-n
	//max=a1&a2&a3...&am  1-m
	//max=max&ai
	
	
	
	
	
	return 0;
}
