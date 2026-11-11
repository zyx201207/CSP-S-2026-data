#include<bits/stdc++.h>
using namespace std;
int a[200005],n,l,r;
long long a1;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	r=n;
	l=1;
	while(1){
		if(c[l]!=c[r]){
			a1+=min(a[l],a[r]);
		}
		if(a[l]>a[r]){
			a[l]-=a[r];
			r--;
		}
		else{
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
			else{
				if(a[l]==a[r]){
					l++;
					r--;
				}
			}
		}
		if(l>r){
			break;
		}	
	}
	cout<<a1;
	return 0;
}
