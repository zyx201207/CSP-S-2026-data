#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int x;char y;
};
int n,a[1000100],sum,ans;char b[1000100];
vector<node>v1,v2;
void cl(int xxs){
	int sum1=0,ii=1;
	for(int i=1;i<=n;i++){
		if(sum1+a[i]==sum/2){
			ii=i+1;
			v1.push_back({a[i],b[i]});
			break;
		}
		if(sum1+a[i]>sum/2){
			v1.push_back({sum/2-sum1,b[i]});
			ii=i;
			a[i]-=sum/2-sum1;
			break;
		}
		sum1+=a[i];
		v1.push_back({a[i],b[i]});
	}
	a[ii]-=xxs;
	for(int i=ii;i<=n;i++) v2.push_back({a[i],b[i]});
	reverse(v2.begin(),v2.end());
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d %c",&a[i],&b[i]),sum+=a[i];
	if(sum%2) cl(1);
	else cl(0);
	int l=0,r=0;
	while(l<v1.size()&&r<v2.size()){
		if(v1[l].x>v2[r].x){
			if(v1[l].y!=v2[r].y) ans+=v2[r].x;
			v1[l].x-=v2[r].x;
			r++;
		}
		else{
			if(v1[l].y!=v2[r].y) ans+=v1[l].x;
			v2[r].x-=v1[l].x;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
