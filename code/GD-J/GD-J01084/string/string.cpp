#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010];
char b[200010];
long long sum,res;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int f=1;
	cin>>a[1]>>b[1];
	for(int i=2;i<=n;i++){
		cin>>a[i]>>b[i];
		if(b[i]!=b[i-1]) f=0;
	}
	if(f) cout<<0;
	else{
		int l=0,r=1,i=1;
		while(i+l<=n+r-i){
			if(b[i+l]==b[n+r-i]){
				if(a[i+l]>a[n+r-i]){
					a[i+l]-=a[n+r-i];
					l--;
				}else if(a[i+l]<a[n+r-i]){
					a[n+r-i]-=a[i+l];
					r++;
				}
				i++;
			}else{
				if(a[i+l]>a[n+r-i]){
					a[i+l]-=a[n+r-i];
					l--;
					res+=a[n+r-i];
				}else if(a[i+l]<a[n+r-i]){
					a[n+r-i]-=a[i+l];
					r++;
					res+=a[i+l];
				}else res+=a[i+l];
				i++;
			}
		}
		cout<<res;
	}
	return 0;
} 






