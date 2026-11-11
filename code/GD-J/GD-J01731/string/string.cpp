#include<bits/stdc++.h>
#define int long long
using namespace std;
struct stu{
	int l,r;
}b[200010];
int n,a[200010],nl,nr,nll,nrr,tl,tr,sum,ss,qwq,ans;
char c[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b[i].l=ss+1;
		b[i].r=ss+a[i];
		ss+=a[i];
	}
	qwq=n;
	for(int i=1;sum<ss/2;i++){
		nl=sum+1,nr=min(ss/2,sum+a[i]);
		nll=ss+1-nr,nrr=ss+1-nl;
		while(b[qwq].l>nrr)qwq--;
		while(1){
			tl=max(max((ss+1)/2+1,b[qwq].l),nll);
			tr=min(b[qwq].r,nrr);
			if(c[qwq]!=c[i]){
				ans+=tr-tl+1;
			}
			if(b[qwq].l<=nll){
				break;
			}
			qwq--;
		}
		sum+=a[i];
	}
	cout<<ans<<endl;
	return 0;
}
