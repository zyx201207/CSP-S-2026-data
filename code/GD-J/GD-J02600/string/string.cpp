#include<bits/stdc++.h>
using namespace std;
struct Nobe{
	long long cnt;
	char c;
};
Nobe a[200005];
long long n,r,l,ll,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].cnt>>a[i].c;
		ll++;
	}
	l=0;
	r=ll;
	while(r>l){
		if(a[l].c==a[r].c){
			if(a[l].cnt>a[r].cnt){
				a[l].cnt-=a[r].cnt;
				r--;
			}else if(a[l].cnt<a[r].cnt){
				a[r].cnt-=a[l].cnt;
				l++;
			}else{
				l++;
				r--;
			}
		}else{
			if(a[l].cnt>a[r].cnt){
				ans+=a[r].cnt;
				a[l].cnt-=a[r].cnt;
				r--;
			}else if(a[l].cnt<a[r].cnt){
				ans+=a[l].cnt;
				a[r].cnt-=a[l].cnt;
				l++;
			}else{
				ans+=a[r].cnt;
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
} 

