#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
struct node{
	char zi;
	int zhi;
};
node a[maxn];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].zhi>>a[i].zi;
	}
	int ans=0;
	int m=n-1;
	for(int i=0;i<n;i++){
		if(i>=m){
			break;
		}
		while(a[i].zhi>0){
			if(a[i].zhi>=a[m].zhi){
				if(a[i].zi==a[m].zi){
					a[i].zhi-=a[m].zhi;
					a[m].zhi=0;
					m--;
				}
				else{
					a[i].zhi-=a[m].zhi;
					ans+=a[m].zhi;
					a[m].zhi=0;
					m--;
				}
			}
			else{
				if(a[i].zi==a[m].zi){
					a[m].zhi-=a[i].zhi;
					a[i].zhi=0;
				}
				else{
					a[m].zhi-=a[i].zhi;
					ans+=a[i].zhi;
					a[i].zhi=0;
				}
			}
		}
	}
	cout<<ans<<endl;
}
