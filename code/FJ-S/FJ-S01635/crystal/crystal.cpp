#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long n,m,k,b,x,fi;
long long a[1000005];
long long s[1000005];
long long o[1000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		k=max(k,a[i]);
		b=i;
	}
	for(int j=n;j>=1;j--){
		int f=0;
		for(int i=1;i<=n;i++){
			x=max(x,a[i]);
			if(f!=x){
				b=i;
			}
			f=x;
		}
		s[j]=x;
		a[b]=0;
		x=-9999999;
	}
	for(int i=n;i>1;i--){
		int p=m;
		for(int j=1;j<i;j++){
			p-=s[i]-s[i-j];
			o[i]+=1;
			if(p<0){
				o[i]--;
				break;
			}
		}	
	}
	for(int i=1;i<=n;i++){
		fi=max(fi,o[i]);
		
	}
	cout<<fi+1;
	return 0; 
}

