#include <bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
long long a[2000005];
long long ans;
long long cnt[2000005];

int count(int l,int r){
	int cnt = 0;
	for(int i = l+1;i <= r-1;i++){
		if(a[i]-a[l]<=d&&a[r]-a[i] <= d){
			cnt++;
		}
	}
	return cnt;
}

void solve1(){
	for(int i = 1;i <= n-3;i++){
		for(int j = i+3;j <= n;j++){
			if(a[j]-a[i] <= d) {
				continue;
//				printf("%d %d %d\n",a[j],a[i],a[j]-a[i]);
			}
//			if(cnt[j] == 1) {
//				ans++;
//				continue;
//			}
			if(count(i,j) == 2){
//				printf("%d %d\n",i,j);
				ans++;
				cnt[j]++;
			}
		}
	}
	cout<<ans<<endl;
}

void solveA(){
	
}
void solveB(){
	
}

//0 2 5 3 -2 -1 0 1 2 6 2 -4 -3 -2 -1 3 6

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans = 0;
		cin>>n>>d;
		for(int i = 1;i <= n;i++){
			scanf("%lld",a+i);
//			cout<<a[i]<<' ';
		}
		solve1();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//0 1 5 3 -3 0 2 3 4
//0 1 7 666666666666666663 -1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
