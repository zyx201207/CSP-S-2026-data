#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=555555;
const int M=333333;
int a[N],v[N];
int f[M],h[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool y=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])y=0;
		h[a[i]]++;
	}
	if(y==1){
		for(int i=1;i<=m;i++){
			h[i]+=h[i-1];
			cout<<h[i]<<" ";
		}
		return 0;
	}
	int len;
	for(int i=1;i<=n;i++){
		len=0;
		for(int j=i;j<=n;j++){
			int p=0;
			for(int k=1;k<=len;k++){                           
				if(v[k]==a[j])p=k;
			}                                             
			if(p==0){                                              
				len++;
				v[len]=a[j];
				continue;
			}                                    
			len=p;                          
		}                                                         
		for(int j=1;j<=len;j++){
			f[v[j]]++;
		}
	}                                                      
	for(int i=1;i<=m;i++){
		cout<<f[i]<<" ";
	}                                              
	return 0;
}
