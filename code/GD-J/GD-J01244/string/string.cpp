#include<bits/stdc++.h>
using namespace std;
struct abc{
	long long l;
	char a;
}a[200010],b[200010],c[200010];
long long l,ans,lb,lc;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].a;
		l+=a[i].l;
	}
	long long s1=0;
	for(int i=1;i<=n;i++){
		if(a[i].l+s1>l/2){
			b[++lb]={l/2-s1,a[i].a};
			s1+=l/2-s1;
			break;
		}
		b[++lb]=a[i];
		s1+=a[i].l;
		if(s1==l/2)break;
	}
	long long s2=0;
	for(int i=n;i>=1;i--){
		if(a[i].l+s2>l/2){
			c[++lc]={l/2-s2,a[i].a};
			s2+=l/2-s2;
			break;
		}
		c[++lc]=a[i];
		s2+=a[i].l;
		if(s2==l/2)break;
	}
	s1=s2=0;
	int x=0,y=0;
	while(x<lb||y<lc){
		if(s1==s2){
			s1+=b[++x].l;
		}else if(s1>s2){
			while(y<lc&&s1>s2){
				++y;
				if(b[x].a!=c[y].a){
					ans+=min(s1,s2+c[y].l)-s2;
				}
				s2+=c[y].l;
			}
		}else{
			while(x<lb&&s1<s2){
				++x;
				if(b[x].a!=c[y].a){
					ans+=min(s2,s1+b[x].l)-s1;
				}
				s1+=b[x].l;
			}
		}
	}
	cout<<ans;
	return 0;
}
