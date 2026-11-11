#include<bits/stdc++.h>
using namespace std;
#define int long long
string s=" ";
struct node{
	int l,c;
	int ed;
	int st;
}a[2000005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin>>n;
	int ed=0;
	for(int i=1;i<=n;i++){
		int l;
		char c;
		cin>>l>>c;
		a[i].st=ed+1;
		ed+=l;
		a[i].l=l,a[i].c=c;
		a[i].ed=ed;
		//cout<<a[i].st<<" "<<a[i].ed<<endl;
	}
	int res=0;
	int i=1,j=n;
	int l=1,r=ed;
	while(i<j&&l<r){
		if(l>a[i].ed)i++;
		if(r>a[j].ed)j--;
		int flag1=a[i].ed-l+1;
		int flag2=r-a[j].st+1;
		if(flag1>flag2){
			if(a[i].c!=a[j].c){
				res+=flag2;
			}
			l+=flag2;
			r=a[j].st-1;
			j--;
		}
		else if(flag1==flag2){
			if(a[i].c!=a[j].c)res+=flag2;
			l=a[i].ed+1;
			r=a[j].st-1;
			i++,j--;
		}
		else{
			if(a[i].c!=a[j].c)res+=flag1;
			r-=flag1;
			l=a[i].ed+1;
			i++;
		}
		//cout<<i<<" "<<j<<" "<<l<<" "<<r<<" "<<flag1<<" "<<flag2<<" "<<res<<endl;
	}
	cout<<res;
	return 0;
}
