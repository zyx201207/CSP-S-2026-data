#include<bits/stdc++.h> 
using namespace std;
int n,m,linshi,result; 
int a[99999999];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	int target[m]={0};
	for(int i=0;i<n;i++){
		cin>>linshi;
		a[linshi]++;
	}
	for(int i=0;i<m;i++){
		for(int i=99999999-1;i>=0;i--)
		{
			if(a[i]!=0){
				target[i]=i+1;
				a[i]-=1;				
			}

	}	
	}
	for(int i=0;i<m;i++){
		if(i==0) result=target[i];
		else result=result&target[i];
	}
	cout<<result<<linshi;
		
	
	
	
	
	
	return 0;
	}
