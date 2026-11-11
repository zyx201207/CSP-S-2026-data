#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+3;

ll len,nbr[N],ans,tmpl,tmpr,mdf;
ll s[N];
int n;
char c[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> nbr[i] >> c[i];
		len+=nbr[i];
		s[i]=s[i-1]+nbr[i];
	}
	tmpl=1;
	for(int i=1,rd=n;i<=n;i++){
		tmpl=tmpl+nbr[i]-1;
		bool brk=false;
		if((len&1)==1 && tmpl>=((len+1)>>1)){
			tmpl=((len+1)>>1)-1;
			brk=true;
		}
		if((len&1)==0 && tmpl>(len>>1)){
			tmpl=(len>>1);
			brk=true;
		}
		tmpr=len-tmpl+1;
//		printf("section[%lld,%lld]\n",tmpl,tmpr);
		for(int j=rd;;j--){
			if(len-mdf<tmpr){
				rd=j;
//				printf("finally,with %d and %d\n",i,rd);
				break;
			}
			if(c[j]!=c[i]) ans+=((len-mdf)-max(tmpr,s[j-1]+1)+1);
			mdf+=((len-mdf)-max(tmpr,s[j-1]+1)+1);
			if(len-mdf<tmpr && s[j-1]<len-mdf){
				rd=j;
				break;
			}
		}
		tmpl++;
//		printf("ans now is %lld\n",ans);
		if(brk==true) break;
	}
	cout << ans;
	return 0;
}
