#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=2e5+17;
ll k,ans=0;
struct str{
	ll sum;
	char c;
}a[M];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>k;
	for(int i=1;i<=k;i++)cin>>a[i].sum>>a[i].c; 
	ll l=1,r=k;
	while(r>l){
//		cout<<"TESTING::"<<l<<" "<<r<<"\n";
		if(a[l].sum>a[r].sum){
//			cout<<"/aaaa/\n";
			if(a[l].c!=a[r].c){
				ans+=a[r].sum;
				a[l].sum-=a[r--].sum;
			}else a[l].sum-=a[r--].sum;
		}else if(a[l].sum==a[r].sum){
//			cout<<"/bbbb/\n";
			if(a[l].c!=a[r].c){
				ans+=a[r].sum;
				l++,r--;
			}else l++,r--;
		}else{
//			cout<<"/cccc/\n";
			if(a[l].c!=a[r].c){
				ans+=a[l].sum;
				a[r].sum-=a[l++].sum;
			}else a[r].sum-=a[l++].sum;
		}
//		cout<<"TESTING2::"<<l<<" "<<a[l].sum<<" "<<r<<" "<<a[r].sum<<"\n";
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

