#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
char b[2000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdin);
    int n,l=1,r;
    long long k=0;
    cin>>n;
    r=n;
    for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		
	}
	while(l<r){
		
		if(a[l]>=a[r]){
			if(b[l]!=b[r]){
				k+=a[r];
				
			}
			a[l]-=a[r];
			r--;
			if(a[l]==0){
				l++;
			}
		}else{
			if(b[l]!=b[r]){
				k+=a[l];
				
			}
			a[r]-=a[l];
			l++;
			
		}
	}
	cout<<k;
    return 0;
}

