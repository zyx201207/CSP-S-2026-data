//GZ-J00551     南白初级中学-王子杰   
#include <bits/stdc++.h>
using namespace std;
struct aaa{
	long long a;
	char c;
};
long long n,ans=0;
aaa m[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>m[i].a>>m[i].c;
		ans+=m[i].a;
	}
	ans/=2;
	long long b=0;
	for(int i=1;i<n;i++){
		if(m[i].c==m[n].c){
			ans-=min(m[i].a+b,m[n].a);
		}
		b=max(m[i].a+b,m[n].a)-min(m[i].a+b,m[n].a);
		n--;
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}

