#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	int l=1,r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
	}
	while(l<=r){
		if(a[l]==a[r]&&b[l]==b[r]){
			l++;
			r--;
		}
		else if(a[l]<a[r]){
			if(b[l]==b[r]){
				a[r]-=a[l];
				l++;

			}
			else{
				cnt+=a[l];
				a[r]-=a[l];	
				l++;
			
			}
		}
		else {
			if(b[l]==b[r]){
				a[l]-=a[r];
				r--;

			}
			else{
				cnt+=a[r];
				a[l]-=a[r];	
				r--;
			
			}
		}

	}
	cout<<cnt;
	return 0;
} 



