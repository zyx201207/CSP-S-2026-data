#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]) break;
		l++;
	}
	int ans=0;
	while(m){		
	    if(m>=l){  
			m-=l;
			ans+=l;      
			for(int i=1;i<=l;i++){            			         
				a[i]++;                           
			}
		}for(int i=1;i<=l;i++){
			if(a[i]==a[i-1]) l++;                                  
		}if(m<l){
			ans+=m;
			break;
		}
	}
	cout<<ans;
	return 0;
}

