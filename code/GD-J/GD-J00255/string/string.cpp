#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}else if(n==2){
		if(c[1]==c[2]){
			cout<<0;
			return 0;
		}else{
			cout<<min(a[1],a[2]);
			return 0;
		}
	}else{
		int l=1,r=n;
		long long sum=0;
		while(l<r){
			if(a[l]==a[r]){
				if(c[l]==c[r]){
					sum+=0;
				}else{
					sum+=a[l];
				}
				l++;
				r--;
			}else if(a[l]<a[r]){
				if(c[l]==c[r]){
					sum+=0;
				}else{
					sum+=a[l];
				}
				a[r]-=a[l];
				l++;
			}else{
				if(c[l]==c[r]){
					sum+=0;
				}else{
					sum+=a[r];
				}
				a[l]-=a[r];
				r--;
			}
		}
		cout<<sum;
	} 
	return 0;
} 
