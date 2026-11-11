#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >>n;
	int m=0;
	for(int i=1;i<=n;i++){
		int da;
		char dc;
		cin>>da>>dc;
		if(m==0)a[++m]=da,c[m]=dc;
		else{
			if(dc==c[m])a[m]+=da;
			else a[++m]=da,c[m]=dc;
		}
	}
	long long l=1,r=n,ans=0;
	while(l<r){
		if(c[l]!=c[r]){
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
			else{
				ans+=a[l];
				r--;
				l++;
			}
		}
		else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
			else{
				r--;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
