#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long cnt,ans;
char c[200005];
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	long long ctn=0;
	for(int i=0;i<n;i++){
		if(ctn+a[i]==cnt/2){
			int l=0,r=n-1;
			while(l<r){
				if(a[l]>=a[r]){
					if(c[l]!=c[r]) ans+=a[r];
					a[l]-=a[r];
					r--;
				}else{
					if(c[l]!=c[r]) ans+=a[l];
					a[r]-=a[l];
					l++;
				}
			}
			break;
		}
		if(ctn+a[i]>cnt/2){
			int l=0,r=n-1,md=i;
			while(l<md&&md<r){
				if(a[l]>=a[r]){
					if(c[l]!=c[r]) ans+=a[r];
					a[l]-=a[r];
					r--;
				}else{
					if(c[l]!=c[r]) ans+=a[l];
					a[r]-=a[l];
					l++;
				}
			}
			if(l==md){
				while(md<r){
					ans+=a[r]; 
					r--;
				}
			}else{
				while(l<md){
					ans+=a[l];
					l++;
				}
			}
			break;
		}
		ctn+=a[i];
	}
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
