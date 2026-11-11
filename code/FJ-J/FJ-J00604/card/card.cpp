#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500000],q[500000],x[500000],xx[500000],b[500000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    long long t=n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int k=1;k<=t;k++){
		memset(x,0,sizeof(x));
		for(int i=1;i<=n;i++){
		    b[i]=a[i];
		}
		for(int i=k;i<=n;i++){
		x[b[i]]=1;
			for(int j=k;j<i;j++){
			if(b[i]==b[j]){
				for(int f=k;f<i;f++){
					x[b[f]]=0;b[f]==-1;
				}x[b[i]]=1;break;
			}
		    }
		    
		}
		for(int f=1;f<=m;f++){
			xx[f]+=x[f];
	}
	}
	for(int f=1;f<=m;f++){
		cout<<xx[f]<<" ";
	}
	return 0;
}
