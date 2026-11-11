#include<bits/stdc++.h>
using namespace std;
int n,ans=0,tail,head;
struct aa{
	int num;
	char s;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	head=1;
	tail=n;
	for(int i=1;i<=n;i++) cin>>a[i].num>>a[i].s;
	while(tail>head){
		//cout<<head<<" "<<tail<<endl;
		int ah=a[head].num;
		int at=a[tail].num;
		if(a[head].s!=a[tail].s) ans+=min(ah,at);
		a[head].num-=min(ah,at);
		a[tail].num-=min(ah,at);
		if(a[head].num==0) head++;
		if(a[tail].num==0) tail--;
	}
	cout<<ans;
	return 0;
}

