#include<bits/stdc++.h>
using namespace std;
struct st{
	long long l;
	long long r;
	char c;
};
long long ans=0;
vector<st> a;
char rf(long long w){
	long long l=1,r=a.size()-1;
	while(l<=r){
		long long mid=(l+r)/2;
		if(a[mid].l>w){
			r=mid-1;
		}else if(a[mid].r<w){
			l=mid+1;
		}else if(a[mid].l<=w&&a[mid].r>=w){
			return a[mid].c;
		}
	}
	return '0';
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	a.push_back({0,0,'0'});
	long long q;
	cin>>q;
	long long dx=1,len=1;
	while(q--){
		long long n;
		cin>>n;
		char c;
		cin>>c;
		a.push_back({a[dx-1].r+1,a[dx-1].r+n,c});
		dx++;
		len+=n;
	}
	for(long long i=len/2,j=(len%2==1?((len+1)/2):len/2);i>0&&j<len;i--,j++){
		char ic=rf(i),jc=rf(j);
		if(ic!=jc) ans++;
	}
	cout<<ans;
	return 0;
} 
