#include<bits/stdc++.h>
using namespace std;
int er(int x){
	
	int a[100005];
	int b=0;
	int c=0;
	int d=1;
	while(x!=0){
		a[c]=x%2;
		x/=2;
		c++;
	}
	for(int i=0;i<c;i++){
		d=1;
		for(int j=0;j<i;j++){d*=10;
		}
		b+=d*a[i];
	}return b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[100005];
	int b[100005];
	int c;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		b[i]=er(a[i]);
	}
	
	if(m==1){
		sort(a,a+n);
		cout<<a[n-1];
	}
	if(m==2){
		int ans[100];
		int x=0;
		int y=0;
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(b[i]>b[j]){c=0;y=b[i];}else{c=0;y=b[j];}
				
					while(y>0){y/=10;c++;}
				for(int k=0;k<c;k++){
					m=10; for(int p=0;p<k;p++){m*=10;
		}
					if(b[i]%m==b[j]%m){ans[99-x]+=m;x++;}else{ans[99-x]+=0;x++;}
				}
				
					
			}
		}sort(a,a+n);
		
			cout<<a[n-2];
		
	}
	if(m!=1&&m!=2){sort(a,a+n);cout<<a[n-2];
	}
	return 0;
}
