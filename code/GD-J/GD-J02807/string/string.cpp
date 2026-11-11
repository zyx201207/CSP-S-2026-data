#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
/*
同步流怎么关来着.?
*/
struct Node{
	char a;
	int n;
}z[maxn];
int n;
signed main(){
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>z[i].n>>z[i].a;
	}int s=z[n].n,r=n,l=1;
	char la=z[n].a;
//	int lun=1;
	while(l<r){
		if(s==0){
			r-=1;
			s=z[r].n;
			la=z[r].a;
		}if(la!=z[l].a){
			if(z[l].n<s){
				ans+=z[l].n;
				s-=z[l].n;
				l+=1;
			}else if(s<z[l].n){
				ans+=s;
				z[l].n-=s;
				s=0;
			}else{
				ans+=s;
				s=0;
				l+=1;
			}
		}else{
			if(z[l].n<s){
				s-=z[l].n;
				l+=1;
			}else if(s<z[l].n){
				z[l].n-=s;
				s=0;
			}else{
				s=0;
				l+=1; 
			}
		}//cerr<<"第"<<lun<<"轮:"<<endl;
		//cerr<<l<<" "<<r<<" "<<ans<<endl;
		//cerr<<s<<" "<<char(la)<<endl;
		//lun+=1;
	}
	cout<<ans;
	return 0;
}
