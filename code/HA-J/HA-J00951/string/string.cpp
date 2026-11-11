#include<bits/stdc++.h>
using namespace std;
long long n,cnt,sum;
struct T{
	long long b;
	char c;
}a[200005],d[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].b>>a[i].c;
		if(d[cnt].c==a[i].c)d[cnt].b+=a[i].b;
		else cnt++,d[cnt].b=a[i].b,d[cnt].c=a[i].c;
	}
	if(cnt==2){
		cout<<d[1].b;
	}else{
		for(int i=1,j=cnt;i<=(cnt+1)/2,j>=(cnt+1)/2;i++,j--){
			if(d[i].c!=d[j].c)sum+=max(d[i].b,d[j].b);
		}
		cout<<sum;
	}
	return 0;
}
