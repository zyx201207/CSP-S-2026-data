//GZ-J00223 ºÎ×ÓÄ¾ 
#include<bits/stdc++.h>
using namespace std;
struct ai{
	long long m;
	string s;
};
ai a[200001];
long long n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].m;
		cin>>a[i].s;
	}
	int l=1,r=n;
	while(r!=l){
		if(a[l].s!=a[r].s){
			if(a[l].m==a[r].m){
				ans+=a[l].m;
				if(r==l+1){
					break;
				}
				l++;
				r--;
			}else if(a[l].m>a[r].m){
				ans+=a[r].m;
				a[l].m-=a[r].m;
				r--;
			}else{
				ans+=a[l].m;
				a[r].m-=a[l].m;
				l++;
			}
		}else{
			if(a[l].m==a[r].m){
				l++;
				r--;
			}else if(a[l].m>a[r].m){
				a[l].m-=a[r].m;
				r--;
			}else{
				a[r].m-=a[l].m;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
