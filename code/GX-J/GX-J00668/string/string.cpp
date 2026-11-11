#include<bits/stdc++.h>
using namespace std;
struct s{
	int num;
	char m;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	long long len=0;
		long long ans=0;
	for(int i=1;i<=n;i++){
		cin >> a[i].num >> a[i].m;
		len+=a[i].num;
		}
	if(n==1){
		cout << 0 << endl;
		return 0;
	}
	int h=1,t=n;
	while(h<t){
		int cnt=min(a[h].num,a[t].num);
		if(a[h].m==a[t].m){
			a[h].num-=cnt;
			a[t].num-=cnt;
		}else{
			a[h].num-=cnt;
			a[t].num-=cnt;
			ans+=cnt;
		}
		//cout << "cnt=" << cnt << endl;
		//printf("a[%d].num=%d\na[%d].num=%d\n",h,a[h].num,t,a[t].num);
		if(a[h].num==0) h++;
		if(a[t].num==0) t--;
		//cout << "h=" << h << endl;
		//cout << "t=" << t << endl;
	}
	cout << ans << endl;
	return 0;
}
