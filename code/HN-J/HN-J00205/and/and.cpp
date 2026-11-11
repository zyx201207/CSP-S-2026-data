#include <bits/stdc++.h>
using namespace std;
long long n,m,ans;

struct asd{
	long long a;
	long long cnt;
}an[200005];

bool cmp(asd a,asd b){
	return a.cnt>=b.cnt;
}

long long cnt_1(long long x){
	long long num=0;
	while(x){
		if(x%2 == 1){
			num++;
			x/=2;
		}
		else x/=2;
	}
	return num;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>an[i].a;
		an[i].cnt = cnt_1(an[i].a);
	}
	sort(an+1,an+n+1,cmp);
	ans = an[1].a;
	for(int i = 1;i<m;i++){
		ans &= an[i+1].a;
	}
	cout<<ans;
	return 0;
} 
