#include<bits/stdc++.h>
using namespace std;
int a[100005];
char c[100005];
long long cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l=0,r;
	cin>>n;
	r=n-1;
	for(int i=0;i<n;i++)cin>>a[i]>>c[i];
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else{
				l++;
				r--;
			}
		}else{
			if(a[l]>a[r]){
				cnt+=a[r];
				a[l]-=a[r];
				r--;
			}else if(a[l]<a[r]){
				cnt+=a[l];
				a[r]-=a[l];
				l++;
			}else{
				cnt+=a[l];
				l++;
				r--;
			}
		}
	}cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
