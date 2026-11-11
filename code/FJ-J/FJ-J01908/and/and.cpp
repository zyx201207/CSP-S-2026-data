#include <bits/stdc++.h>
using namespace std;
long long a[200001];
int main(){
	
	freopen("and.in","r","stdin");
	freopen("and.out","w","stdout");
	long long maxa=0;
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
		if(a[i]>maxa){
			maxa=a[i];
		}
		
	} 
	
	int i=0;
	while(maxa){
		maxa/=2;
		i++;
	}
	
	
	long long ans=0;
	int cnt=n;
	while(i){
		int flag=0;
		int b=pow(2,i-1);
		for(int j=1;j<=n;j++){
			if(a[j]==0)continue;
			if(a[j]>=b)flag++;
		}
		
		if(flag>=m){
			cnt=flag;
			ans+=b;
			
			for(int j=1;j<=n;j++){
				if(a[j]<b)a[j]=0;
				else a[j]-=b;
			}
			
		}
		else{
			ans+=0;
			
			for(int j=1;j<=n;j++){
				if(a[j]>=b)a[j]-=b;
			}
		} 
		i--;
	}
	cout<<ans;
}

