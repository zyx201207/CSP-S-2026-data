#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int mxn=0,mxn2=0,cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt+=a[i];
		if(a[i]>mxn){
			mxn=a[i];
		}
	}
	if(m==1){
		cout<<mxn;
	}else if(m==n){
		cout<<cnt;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(a[i]+a[j]>mxn){
					mxn=a[i]+a[j]; 
				}
			}
		}
		cout<<mxn;
	}
	return 0;
}
