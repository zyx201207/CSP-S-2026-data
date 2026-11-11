#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	int ans=0;
	long long d=2e9+10,d2=2e9+10,ds=1,ds2=1;
	for(int i=0;i<n;++i){
		if(a[i]<d){
			d=a[i];
			ds=1;
		}
		else if(a[i]==d) ds++;
		else if(a[i]>d){
		    if(a[i]<d2){
			    d2=a[i];
			    ds2=1;
			} 
			else if(a[i]==d2) ds2++;
		}
	}
	for(int i=0;i<n;++i){
		int s=0;
		if(m!=0){
			for(int j=0;j<n;++j){
				if(a[j]==d){
					if(m!=0){
						m--;
					    a[j]+=1;
						}
				} 
			}
			int z=0;
			for(int j=0;j<=n;++j){
				if(a[j]==d2) s++;
				else if(a[j]==d+1) z++;
			}
			if(s==ds+ds2||z==ds){
				if(s==ds+ds2){
					ans=ds+ds2;
				}
				d=2e9+10,d2=2e9+10,ds=1,ds2=1;
				for(int j=0;j<n;++j){
		        if(a[j]<d){
			        d=a[j];
			        ds=1;
		        }
		        else if(a[j]==d) ds++;
		        else if(a[j]>d){
		            if(a[j]<d2){
			            d2=a[j];
						ds2=1;
			        } 
			    else if(a[j]==d2) ds2++;
		        }
	          }
			}
		}
	}
	cout<<ans;
	return 0;
}
