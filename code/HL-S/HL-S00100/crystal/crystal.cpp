#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,cnt,a[500010],b[500010];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int mid=(n-1)/2;
	for(int i=0;i<n;i++){
		b[i]=abs(mid-a[i]);
	}
	int l=mid-1,r=mid+1;
	while(m>0){
		if(b[l]<b[r]){
			if(m-b[l]<0){
				break;
			}
			m-=b[l];
			l--;
		}else{
			if(m-b[r]<0){
				break;
			}
			m-=b[r];
			r++;
		}
		cnt++;
	}
	cout<<cnt;
	return 0;
}
