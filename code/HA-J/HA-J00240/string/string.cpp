#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum=0,s=0,l[200005],r[200005],cnt=0,f;
char c[20005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		l[i]=s+1;
		s+=a[i];
		r[i]=s;
	}
	int x=0,y=n;
	while(f){
		if(x==y)
			f=1;
		if(c[x]==c[y]){
			int r1=sum-l[y]+1,l1=sum-r[y]+1;
			cnt+=min((abs(r1-l[x])),(abs(l1-r[x])))+1;
		}
		if(l[x]+r[y]<=sum)
			x++;
		else
			y--;
	}
	cout<<(sum-cnt*2)/2;
	return 0;
}
