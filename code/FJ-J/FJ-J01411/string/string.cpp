#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010];
char c[200010];
long long s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(a[l]>a[r]){
			if(c[l]!=c[r]){
				s+=a[r];
				a[l]-=a[r];
			}
			r--;
		}
		else if(a[r]>a[l]){
			if(c[l]!=c[r]){
				s+=a[l];
				a[r]-=a[l];
			}
			l++;
		}
		else{
			if(c[l]!=c[r]){
				s+=a[l];
			}
			l++;
			r--;
		}
	}
	cout<<s<<endl;
	return 0;
} 
