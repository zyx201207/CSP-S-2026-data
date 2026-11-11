#include<bits/stdc++.h>
using namespace std;
struct f{
	long long c;
	string k;
}a[100005];
long long n,s,l,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].c>>a[i].k;
		s+=a[i].c;
	}
	for(int i=1,j=n;;){
		l+=min(a[i].c,a[j].c);
		if(l>s/2)a[i].c=s/2-min(a[i].c,a[j].c),a[j].c=s/2-min(a[i].c,a[j].c);
		if(a[i].k!=a[j].k)ans+=min(a[i].c,a[j].c);
		if(a[i].c<a[j].c)a[j].c-=a[i].c,i++;
		else if(a[i].c>a[j].c)a[i].c-=a[j].c,j--;
		else i++,j--;
		if(l==s/2)break;
	}
	cout<<ans;
	return 0;
}
