#include<bits/stdc++.h>
using namespace std;

long long n,m=0,m1,cnt=0; 
int a[500001]={};
int a1[50001]={};
int a2[50001]={};

int main(){
	
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	
	cin>>n>>m;
	int f=(n+1)/2+1;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(int i=0;i<n-1;i++){
		int o=a[i+1];
		if(a[i+1]<a[i]){
			a[i+1]=a[i];
			a[i]=o;
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]>a[f])
			a1[i]=a[i]-a[f];
		else
			a1[i]=a[f]-a[i];
	}

	for(int i=a[0]-m;i<a[n];i++){
		for(int j=0;j<n;j++){
			if(a[j]>i)
				a2[j]=a[j]-i;
			else
				a2[j]=i-a[j];
			if(a2[j]<=m && max(a2[j],a2[j+1]))
			{
			cnt++;
			continue;
			}
		}
		
		
	}
	
	cout<<cnt<<endl;
	
	return 0; 
}
