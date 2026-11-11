#include<iostream>
#include<algorithm>
using namespace std;
int arr[36],s[10000000],mid=0;
bool imaxn(int a,int b){
	while(a != 0 && b != 0){
		a>>=1,b>>=1;
	}
	if(a==b){
		return 1;
	}
	return 0;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,maxn=0,mxid=0;
	cin>>n>>m;
	cin.tie(0);
	cout.tie(0);
	m--;
	for(long long i = 0;i < n;i++){
		cin>>s[i];
	}
	sort(s,s+n);
	long long a=1;
	for(long long i = n-1;i >= 0;i--){
		if(imaxn(s[i-1],s[i])){
			mid=i;
			break;
		}
		a++;
	}
	long long ans = s[n-a],t=s[n-a];
	for(long long i = n-2;i>=0;i--){
		if(i == mid){
			continue;
		}
		if(s[i] & ans){
			m--;
			ans &= s[i];
		}
		if(m == 0){
			break;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
