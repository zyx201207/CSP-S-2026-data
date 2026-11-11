#include<bits/stdc++.h>
using namespace std;
int n;
struct p{
	int x;
	char y;
}le[200005];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>le[i].x>>le[i].y;
	}
	int l=1,r=n;
	while(l<r){
		if(le[l].x==le[r].x&&le[l].y==le[r].y){
			l+=1,r-=1;
			continue;
		}
		if(le[l].y==le[r].y){
			if(le[l].x>le[r].x){
				le[l].x-=le[r].x;
				r--;
			}
			else{
				le[r].x-=le[l].x;
				l++;
			}
			continue;
		}
		if(le[l].x>le[r].x){
			ans+=le[r].x;
			le[l].x-=le[r].x;
			r--;
			}
		else if(le[l].x<le[r].x){
			ans+=le[l].x;
			le[r].x-=le[l].x;
			l++;
			}
			else{
				ans+=le[l].x;
				l++,r--;
			}
	}
	cout<<ans;
	return 0;
}
