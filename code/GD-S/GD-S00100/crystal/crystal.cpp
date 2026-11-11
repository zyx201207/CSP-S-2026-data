#include<bits/stdc++.h>
using namespace std;
long long a[10000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,p=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i){
			p++;
		}
	}
	int h=a[2]-a[1];
	if(p==n){
		int k=0,l=0,r=1;
		while(m>0){	
			l+=r;
			m-=l;
			if(m<=0){
				break;
			}
			r++;
			k++;
		}
		cout<<k+1;
	}else{
		int k=0,l=h,r=h;
		while(m>0){
			m-=l;
			if(m<=0){
				break;
			}
			k++;
			r+=h;
			l+=r;
		}
		cout<<k;
	}
	return 0;
} 
