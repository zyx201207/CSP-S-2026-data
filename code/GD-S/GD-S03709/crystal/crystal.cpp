#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int n,m;
int ans;
int a[N],b[N],s[N];
/*
void doit(int x){
	int cnt =2;
	for(int i = x;i <= n;i++){
		b[i] = a[i]-a[i-1];
		s[i] = s[i-1]+b[i]*(cnt-1);	
		if(s[i] > m){
			ans = max(ans,cnt-1);
			return ;
		}	
	}
	ans = max(ans,cnt-1);
	return ;
}*/
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
//		cin >> a[i];
	} 
	sort(a+1,a+1+n);
	int ans = 0;
	for(int i = 2;i <= n;i++){
		b[i] = a[i]-a[i-1];
		s[i] = s[i-1]+b[i]*(i-1);
		if(s[i] > m){
			ans = i-1;
			break;
		}
		
	}

/*
	int cnt = 2;
	for(int i = 2;i <= n;i++){

//		printf("ts:s[%lld] = %lld\n",i,s[i]);
		if(s[i] > m){
//			printf("	ts:cnt=%lld\n",cnt);
			ans = max(ans,cnt-1);
			s[i] = 0;
			cnt = 2;
//			i++;
			continue;
//			break;
		}
//		printf("		ts:s[%lld] = %lld\n",i,s[i]);
		cnt++;
	}*/
//	doit(2);
	printf("%lld",ans);
	return 0;
}
