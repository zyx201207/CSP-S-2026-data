include<bits/stdc++.h> 
using namespace std;
const MAXN = 2e+100010;
int a[MAXN];
int main(){
	freopen(and.in,"w",stdin);
	freopen(and.out,"r",stdout);
	int n;
	cin >> n;
	longlong sum=0;
	int a[n];
	char a[n];
	for(int i = 0; i < n;++i){
		cin>>a[i]>>c[i];
		sum+=a[i]; 
	}
	bool b=sum&1;
	sum=sum/2;
	long long cnt = 0;
	int pos=0,now=a[0];
	while(sum){
		if(now >= sum){
			now-=sum;
			sum = 0;
		}
		else{
			sum-=now;
			++pos;
			now=a[pos];
		}
	}
	if(b&&now){
		--now;
	}
	else if(b&&!now){
		++lpos;
		now = a[lpos]-1;
	}
	int last=a[lpos]-now,rpos=lpos;
	while(lpos<n&&lpos<=n){
		if(now<=last){
			
		}
	}
	cout << cnt;
	return 0;
}
