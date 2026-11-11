#include<bits/stdc++.h>
using namespace std;
struct s{
	long long l;
	char c;
}a[200001];
long long le,ri,cnt;
long long ans;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n;cin>>n;ri=n-1;
	for(long long i=0;i<n;i++){
		cin>>a[i].l>>a[i].c;
		cnt+=a[i].l;
	}
	for(int i=0;i<n-1;){
		long long w=min(a[le].l,a[ri].l);
		if(a[le].c!=a[ri].c){
			ans+=w;
		}
		a[le].l-=w;a[ri].l-=w;
		if(a[le].l==0){
			le++;i++;
		}if(a[ri].l==0){
			ri--;i++;
		}
	}
	cout<<ans;
} 
