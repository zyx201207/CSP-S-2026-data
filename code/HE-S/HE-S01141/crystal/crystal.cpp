#include<bits/stdc++.h>
using namespace std;
long long a[500005];
vector<long long> sub;
int main(){
	freopen("crystal.in","w",stdin);
    freopen("crystal.out","r",stdout);
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]); 
	}
	sort(a+1,a+n+1);
	long long mid=a[(1+n)/2];
	for(int i=1;i<=n;i++){
		if(a[i]<=mid) sub.push_back(mid-a[i]);
		else sub.push_back(a[i]-mid); 
	}
	sort(sub.begin(),sub.end());
	int h=0;
	for(int i=0;i<sub.size();i++){
		if(m-sub[i]>=0){
			m-=sub[i];
			h++;
		}
		if(m-sub[i]<0){
			break;
		}
	}
	printf("%d\n",h);
	return 0;
} 
