#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,ans=0;
int A[20007];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	if(m==1){
		for(int i=0;i<n;i++){
			if(A[i]>ans){
				ans=A[i];
			}
		}
	}else if(m==n){
		ans=A[0];
		for(int i=1;i<n;i++){
			ans=ans&A[i];
		}
	}else if(n>2000 and A[0]<4){
		if(m==1){
			for(int i=0;i<n;i++){
				if(A[i]>ans){
					ans=A[i];
				}
			}	
		}
	}else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if((A[i]&A[j])>ans){
					ans=A[i]&A[j];
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 
