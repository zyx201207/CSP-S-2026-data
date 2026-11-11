/*
3
2 a
2 b
1 c
2
2 a
3 a
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
#include<bits/stdc++.h>
using namespace std;
long long n,t[200010],cnt=0;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>t[i]>>c[i];
	}
	long long l=1,r=n;
	while(l<=r){
		if(c[l]==c[r]){
			if(t[l]>t[r]){
				t[l]=t[l]-t[r];
				t[r]=0;
				r--;
			}else if(t[l]<t[r]){
				t[r]=t[r]-t[l];
				t[l]=0;
				l++;
			}else if(t[l]==t[r]){
				t[l]=0;
				t[r]=0;
				l++;
				r--;
			}
		}else{
			if(t[l]>t[r]){
				cnt+=t[r];
				t[l]=t[l]-t[r];
				t[r]=0;
				r--;
			}else if(t[l]<t[r]){
				cnt+=t[l];
				t[r]=t[r]-t[l];
				t[l]=0;
				l++;
			}else if(t[l]==t[r]){
				cnt+=t[l];
				t[l]=0;
				t[r]=0;
				l++;
				r--;
			}
		}
	}
	cout<<cnt;
	return 0;
}
