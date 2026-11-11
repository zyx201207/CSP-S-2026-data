//刘子逍 北京师范大学贵阳附属中学 GZ-J00306
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
struct T{
	ull n;
	char c;
}a[200010];
ull n,ln,mid,lm,rm,ans,l,r;
int main(){
	//freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	cin>>n;
	int inx=1;
	while(n--){
		cin>>a[inx].n>>a[inx].c,ln+=a[inx].n;
		if(a[inx].c==a[inx-1].c) a[inx-1].n+=a[inx].n;
		else ++inx;
	}
	/*lm=a[1].n,rm=a[inx-1].n,l=1,r=1;
	cout<<((ln-(ln%2))/2)<<' '<<((ln-(ln%2))/2+!(ln%2))<<'\n';
	cout<<lm<<' '<<ln-rm<<'\n';
	while(lm<() || ln-rm>((ln-(ln%2))/2+1)){
		if(a[l].c!=a[inx-r].c) ans+=min(a[l].n+lm,a[inx-r].n+rm)-max(lm,rm);
		if(a[l].n+lm>=a[inx-r].n+rm) rm+=a[inx-r].n,++r;
		if(a[l].n+lm<=a[inx-r].n+rm) lm+=a[l].n,++l;
	}
	cout<<ans<<'\n';*/
	//cout<<'\n';
	//for(int i=1;i<inx;++i) cout<<a[i].n<<' '<<a[i].c<<'\n';
	
	cout<<(ln-(ln%2))/2<<'\n';
	//fclose(stdin);fclose(stdout);
	return 0;
}
/*
3
2 a
2 b
1 c
*/

