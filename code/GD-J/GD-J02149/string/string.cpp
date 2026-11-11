#include <iostream>
using namespace std;
#define int long long
int n;
struct Pus{
	int l;
	char c;
}a[200000];
long long ans=0;
int l,r;
int s1,s2;
signed main(){
	freopen("string.in","rb",stdin);
	freopen("string.out","wb",stdout);
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i].l>>a[i].c;
	l=0,r=n-1;
	s1=a[l].l,s2=a[r].l;
	while(l<r){
		if(s1==s2){
			if(a[l].c!=a[r].c)ans+=s1;
			++l,--r;
			s1=a[l].l,s2=a[r].l;
		}else if(s1<s2){
			if(a[l].c!=a[r].c)ans+=s1;
			s2-=s1;
			++l,s1=a[l].l;
		}else{
			if(a[l].c!=a[r].c)ans+=s2;
			s1-=s2;
			--r,s2=a[r].l;
		}
//		cout<<l<<' '<<r<<':'<<s1<<' '<<s2<<'\n';
	}
	cout<<ans;//COUT
	return 0;
}
