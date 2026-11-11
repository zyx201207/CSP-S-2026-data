#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
long long n,m,a[5*114514];
long long solve(long long c,long long num){
	long long tmp=num;
	long long ans=1;
	for(long long i=1;tmp-i>=0;i+=c){
		if(ans>n){
			return n;
		}
		tmp-=i;
		ans++;
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	long long cha=a[1]-a[0];
	cout<<solve(cha,m);
	return 0;
} //crystal
