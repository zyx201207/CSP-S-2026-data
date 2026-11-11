#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],op,cnt,p,k,l;
bool f=1;
bool ss(int a[]){
	int u=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=u){
			return 0;
		}	
	} 
	return 1;
}
bool s(int a[]){
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			return 0;
		}	
	} 
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	if(n==1){
		cout<<1;
		return 0;
	}   
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	} 
	sort(a+1,a+1+n);
	if(s(a)){
		while(1){
			k++;
			if(k*(k+1)/2<=m){
				l=k+1;
			}else break;
		}
		cout<<min(l,n);
	}
	else{
		for(int i=1;i<=n;i++){
			for(int k=1;k<=i;k++){
				op=0;
				cnt=0;
				for(int j=k;j<=i;j++){
					op=op+(a[i]-a[j]);
					if(op>m){
						break;	
					}
					else cnt++;
				}
				p=max(p,cnt);
			}
		}
		cout<<p;
	}
	return 0;
} 
