#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[210000]={0};
int c[210000]={0};
int book[210000]={0};
long long ans=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		a[i]=x;
		c[i]=y-'a';
	}
	int l=1,r=n;
	int l_cnt=0;
	while(l<r&&l<=n&&r>=1){
		l_cnt+=a[l];
		book[l]=1;
		while(l_cnt>0&&l<r&&l<=n&&r>=1){
			//cout<<l<<" "<<r<<" "<<ans<<" "<<l_cnt<<endl;
			l_cnt-=a[r];
			if(l_cnt<0){
				while(l_cnt<0&&l<r&&l<=n&&r>=1){
				if(c[l]!=c[r]){
					ans+=a[l];
				}
				l++;
				l_cnt+=a[l];
			}
			}
			
			
			r--;
		}
		l++;
	}
	cout<<ans;
	return 0;
}
