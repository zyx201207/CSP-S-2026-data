//GZ-J00702 遵义市第十九中学 毛文颢
#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	int cnt1=0,cnt2=0,temp1=a,temp2=b;
	while(temp1){
		if(temp1%2!=0) break;
		cnt1++;
		temp1/=2;
	}
	while(temp2){
		if(temp2%2!=0) break;
		cnt2++;
		temp2/=2;
	}
	return (pow(2,cnt1)-a)<(pow(2,cnt2)-b)||(((pow(2,cnt1)-a)==(pow(2,cnt2)-b))&&(a>b));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200000];
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	int ans=a[0];
	for(int i=1;i<m;i++){
		ans&=a[i];
	}
	cout<<ans;
	
	return 0;
}
