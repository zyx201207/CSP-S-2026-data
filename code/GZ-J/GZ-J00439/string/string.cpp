//GZ-J00439 贵阳市第一中学 徐錦鴻 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
struct node{
	char x;int y;
}k[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char a;int s;cin>>s>>a;
		k[i].x=a;k[i].y=s;
	}
	int j=n,i=1;
	while(i<=j){
		if(k[i].x!=k[j].x){
			if(k[i].y>k[j].y) ans+=k[j].y,k[i].y-=k[j].y,j--;
			else if(k[i].y=k[j].y) ans+=k[i].y,i++,j--;
			else ans+=k[i].y,k[j].y-=k[i].y,i++;
		}else{
			if(k[i].y>=k[j].y) k[i].y-=k[j].y,j--;
			else if(k[i].y=k[j].y) i++,j++;
			else k[j].y-=k[i].y,i++;
		}
	}
	cout<<ans;
	return 0;
}



