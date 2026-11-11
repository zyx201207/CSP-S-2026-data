#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],l=0,cnt=0,minn;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	int w1=0,w2=n;
	long long s=0;
	while(s<l/2&&w1<w2){
		if(a[w1]<=0) w1++;
		if(a[w2]<=0) w2--;
		minn=min(a[w1],a[w2]);
		if(c[w1]!=c[w2]){
			cnt+=minn;
		}
		a[w1]-=minn;
		a[w2]-=minn;
		s+=minn;
	}
	cout<<cnt;
	return 0;
}

