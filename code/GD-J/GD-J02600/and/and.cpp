#include<bits/stdc++.h>
using namespace std;
int n,m,ch,x,y,ans;
int a[200007],cnt[50],aa[50];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(a[i]==x){
			ch++;
		}
		x=a[i];
		y=0;
		while(a[i]){
			aa[y]=a[i]%2;
			a[i]/=2;
			y++;
		}
		for(int j=0;j<=y;j++){
			cnt[j]+=aa[y-j-1];
		}
	}
	for(int i=0;i<y;i++){
		if(cnt[i]>=m+ch){
			ans+=pow(2,i);
		}
	}
	cout<<ans;
	return 0;
} 
