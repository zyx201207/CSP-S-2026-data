#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
char c[2000010];
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int l=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}for(int i=2;i<=n;i++){
		if(c[i]==c[i-1]){
			a[l]+=a[i];
		}else{
			l++;
			a[l]=a[i];
			c[l]=c[i];
		}
	}n=l;
	l=1;
	int r=n;
	long long cnt=0;
	while(l<r){
		if(a[l]>a[r]){
			if(c[l]==c[r])a[l]-=a[r],r--;
			else{
				cnt+=a[r];
				a[l]-=a[r];
				r--;
			}
		}else if(a[l]==a[r]){
			if(c[l]==c[r])l++,r--;
			else cnt+=a[r],l++,r--;
		}else {
			if(c[l]==c[r])a[r]-=a[l],l++;
			else{
				cnt+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
	}cout<<cnt;
	return 0;
}
