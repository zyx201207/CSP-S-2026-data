#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2*100000+5],ans,d,x,y,b,c;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=d)
		d=a[i];
	}
	if(m==1){
		cout<<d;
		return 0;
	}
	d=0;
	if(m==2){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			c=a[i]&a[j];
			if(c>d){
				d=c;
			}
		}
	}
	cout<<d;
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				c=a[i]&a[j];
				if(c>d){
					d=c;
					x=i,y=j;
				}
			}
		}
		a[x]=0,a[y]=0,m-=2;
		while(m!=0){
			for(int i=1;i<=n;i++){
				c=a[i]&d;
				if(c>b){
					b=c;
					x=i;
				}
		    }
			m--;
			d=b;
			b=0;
		}
		
		cout<<d;
	}
	return 0;
} 
