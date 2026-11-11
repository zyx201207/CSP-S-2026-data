#include<iostream>
#define int long long
using namespace std;
const int N=2e5+5;
int n,len=0,l=1,r,cur,ans;
struct node{
	int num;
	char ch;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cur=n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].ch;
		len+=a[i].num;
	}
	int mid=(len)>>1;
	r=len;
	for(int i=1;i<=n;i++){
		int num=min(l+a[i].num-1,mid); //l-num
		int tmp=len-num+1; //tmp-r
		if(num==tmp)break;
		while(1){
			if(r-a[cur].num+1<tmp){
				a[cur].num-=(r-tmp+1);
				if(a[cur].ch!=a[i].ch)ans+=(r-tmp+1);
				break;
			}else{
				if(a[cur].ch!=a[i].ch)ans+=a[cur].num;
				r-=a[cur].num;
				cur--;
			}
			if(r==tmp-1)break;
		}
		l=num+1;r=tmp-1;
		if(l>mid)break;
	}
	cout<<ans;
}
