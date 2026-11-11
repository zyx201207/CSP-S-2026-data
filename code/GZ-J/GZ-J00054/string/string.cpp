//GZ-J00054 ÀÔ–°∫≠ 
#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	long long s=0;
	while(l<r){
		if(c[l]!=c[r]){
			if(a[l]<a[r]){
				s+=a[l];
				a[r]-=a[l];
				l++;
			}
			else if(a[l]>a[r]){
				s+=a[r];
				a[l]-=a[r];
				r--;
			}
			else{
				s+=a[l];
				l++;
				r--;
			}
		}
		else{
			if(a[l]==a[r]){
				l++;
				r--;
			}
			else{
				if(a[l]<a[r]){
					a[r]-=a[l];
					l++;
				}
				else if(a[r]<a[l]){
					a[l]-=a[r];
					r--;
				}
			}
		}
	}
	cout<<s;
	return 0;
} 
