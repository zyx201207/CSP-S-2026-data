#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define ll long long
struct duan{
	ll num;
	int name;
	ll rem;
}a[N];

int n;
ll cntl,cnt,ans=0;
int l,r;


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char x;
	cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
		cin>>x;
		a[i].name=int(x-'a'+1),cnt+=a[i].num,a[i].rem=a[i].num;
	}
	cntl=0,l=1,r=n;
	ll dc;
	while(l<r){
		dc=min(a[l].rem,a[r].rem);
		if(a[l].name!=a[r].name){
			ans+=dc;
		}
		a[l].rem-=dc,a[r].rem-=dc;
		if(a[l].rem==0){
			l++;
		}
		if(a[r].rem==0){
			r--;
		}
	}
	//cout<<l<<" "<<r<<endl;
	//if(l>r){
		cout<<ans;
		return 0;
	//}
	
	//return 0;
}
