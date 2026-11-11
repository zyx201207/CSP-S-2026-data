#include<bits/stdc++.h>
using namespace std;
int n,m,ma=0,x,t;
int a[100010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=x){
			x=a[i];
		}
	}
	if(m==1){
		cout<<x<<endl;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				t=a[i]&a[j];
				if(t>=ma){
					ma=t;
				}
			}
		}	
		cout<<ma<<endl;
		return 0;
	}
	return 0;
} 
