#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000098];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,num=1,flg=0;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			num++;
		}
		else if(a[i]-a[l]<=m){
			m-=a[i]-a[l];
			num++;
			if(i>l&&flg==0){
				flg=i;
			}
		}else if(a[i]-a[l]>m&&(a[i]-a[l+1]<a[i-1]-a[l])){
				l+=1;
				m+=a[l-1];
		}
	}
	cout<<num;
	return 0;
}
