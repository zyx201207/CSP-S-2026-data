#include<bits/stdc++.h>
using namespace std;
long long sum,cnt,n,a[200020];
char c[200020];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(r>l){
		if(c[l]!=c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				cnt+=a[r];
				r--;
			}
			else if(a[l]==a[r]){
				cnt+=a[l];
				r--;
				l++;
			}
			else{
				a[r]-=a[l];
				cnt+=a[l];	
				l++;
			}
		}
		else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else if(a[l]==a[r]){
				r--;
				l++;
			}
			else{
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<cnt;
	return 0;
}

