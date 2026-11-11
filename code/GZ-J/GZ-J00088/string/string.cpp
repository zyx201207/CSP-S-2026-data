//GZ-J00088 遵义市新蒲新区天立学校 袁铭骏侨 
#include<bits/stdc++.h>
using namespace std;
struct dl{
	long long a;
	char c;
}d[50000005];
long long ans,n,w;
int main(){
	freopen("string6.in","r",stdin);
	freopen("string6.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>d[i].a>>d[i].c;
		w+=d[i].a;
	}
	int l=1,r=n;
	for(int i=1;i<=w/2;i++){
		if(!d[l].a){
			l++;
		}
		if(!d[r].a){
			r--;
		}
		d[l].a--;
		d[r].a--;
		if(d[l].c!=d[r].c){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
