#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct Nove{
	int a;
	char c;
}a[114514*2];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
	}
	int ans=0;
	int j=n,li=0,lj=0,si=0,sj=a[n].a;
	for(int i=0;i<j;){
		if(si<=sj){
			i++;
			if(a[i].c!=a[j].c&&si<sj){
				ans+=min(sj-si,a[i].a);
			}
			si+=a[i].a;
		}else{
			j--;
			if(a[i].c!=a[j].c){
				ans+=min(si-sj,a[j].a);
			} 
			sj+=a[j].a;
		}
//		cout<<ans<<' '<<i<<' '<<j<<' '<<si<<' '<<sj<< endl;
	}
	cout<<ans;
}//I love cyq
