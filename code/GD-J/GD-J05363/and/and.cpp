#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int o[n+5];
	int map[n+5]; 
	int lmap[n+5];
	long long ans=0;
	int w=0;
	long long a[n+10];
	for(int i=0;i<n;i++){
	    cin>>a[i];
	    o[i]=a[i];
	}
	int b[n+10][35];
	for(int i=0;i<n;i++){
		int k=0;
		while(a[i]){
			b[i][k]=a[i]%2;
			a[i]=a[i]/2;
			k++;
		}
		w=max(w,k);
	}
	int i=w;
	int k=n;
	for(int j=0;j<n;j++){
		map[j]=j;
	}
	while(w){
		int l=0;
        for(int j=0;j<k;j++){
        	if(b[map[j]][w]==1){
        		lmap[l]=j;
        		l++;
			}
		}
		if(l>=m){
			for(int h=0;h<l;h++){
				map[l]=lmap[l];
			}
			if(l==m){
				ans=o[map[0]];
				for(int h=1;h<m;h++){
					ans=ans & o[map[h]];
				}
				cout<<ans;
				return 0;
			}
		}
		w--;
	}
	ans=o[map[0]];
	for(int h=1;h<m;h++){
		ans=ans & o[map[h]];
	}
	cout<<ans;
	return 0;
}
