#include<bits/stdc++.h>
using namespace std;

long long n,m,a[90000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxx=0;
	int s=0;
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>maxx){
				maxx=a[i];
			}
		
		}
		cout<<maxx;
		return 0;
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]&a[j]>maxx){
					maxx=a[i]&a[j];
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	while(m>0){
		maxx=0;
		int maxxi=0,maxxj=0;
		if(s==0){
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[i]&a[j]>maxx){
						maxx=a[i]&a[j];
						maxxi=i;
						maxxj=j;
					}
				}
			}
			s=maxx;
			
			a[maxxi]=0;
			a[maxxj]=0;
			m=m-2;
			
		}
		maxx=0;
		maxxi=0,maxxj=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				i++;
			}
			if(a[i]&s>maxx){
				maxx=s&a[i];
				
				maxxi=i;
			}
			
		}
		s=maxx;
		a[maxxi]=0;
		m--;
	}
	
	cout<<s;
	return 0;
}
