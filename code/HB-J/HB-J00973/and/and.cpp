#include<bits/stdc++.h>
using namespace std;
int  k[23],h[23],o3[23];
int f(int a,int b){
	int t=0;
	int  j1=1,k2[23],h2[23];
	for(int i=0;i<=22;i++){k2[i]=0;}
	for(int i=0;i<=22;i++){h2[i]=0;}
	for(int i=0;i<=22;i++){k[i]=0;}
	for(int i=0;i<=22;i++){h[i]=0;}
	for(int i=0;i<=22;i++){o3[i]=0;}
	for(int i=a;i!=0;i/=2){
		k2[j1]=i%2;
		j1++;
	}
	for(int i=22;i>=1;i--){
		if(k2[i]==1){
			for(int j=i;j>=1;j--){
				k[23-j]=k2[j];
			}
			break;
		}
	}
	j1=1;
	for(int i=b;i!=0;i/=2){
		h2[j1]=i%2;
		j1++;
	}
	for(int i=22;i>=1;i--){
		if(h2[i]==1){
			for(int j=i;j>=1;j--){
				h[23-j]=h2[j];
			}
			break;
		}
	}
	for(int i=22;i>=1;i--){
		if(k[i]==1&&h[i]==1){
			o3[i]=1;
		}
	}
	for(int i=1;i<=22;i++){
		if(o3[i]==1){
			int g=1;
			for(int j=1;j<=22-i;j++){
				g*=2;
			}
			t=t+g;
		}
	}
	int t1=t;
	t=0;
	return t1;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n,q=0;
    cin>>n>>m;
    int a[n+1];
    if(m==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(q<=a[i]){
				q=a[i];
			}
		}
		cout<<q;
	}
	if(m==2){
		for(int i=1;i<=n;i++){cin>>a[i];}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(f(a[i],a[j])>=q){
					q=f(a[i],a[j]);
				}
			}
		}
		cout<<q;
	}
	if(m==n){
		for(int i=1;i<=n;i++){cin>>a[i];}
		q=a[1];
		for(int i=2;i<=n;i++){
			q=f(q,a[i]);
		}
		cout<<q;
	}
	if(m==n-1){
		int s=1;
		for(int i=1;i<=n;i++){cin>>a[i];}
		for(int i1=1;i1<=n;i1++){
			if(s!=1){q=a[1];}
		   	if(s==1){q=a[2];}
		    for(int i=2;i<=n;i++){
				if(s!=i){
		    	    if(q<=f(q,a[i])){q=f(q,a[i]);};
			    }
	    	}
	    	s++;
	    }
		cout<<q;
	}
    return 0;
}
