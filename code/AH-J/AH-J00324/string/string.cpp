#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,t=1,t1;
struct stu{
	ll score;
	char c;
}a[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i].score>>a[i].c;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	int q=a[1].c;
	for(ll i=2;i<=n;i++){
		if(a[i].c==q){
			t++;
		}else{
			t1++;
		}
	} 
	if(t==n){
		cout<<0;
		return 0;
	}
	ll s1=a[1].score,s2=0;
	for(ll i=2;i<=n;i++){
		if(a[i].c==q){
			s1+=a[i].score;
		}else{
			s2+=a[i].score;
		}
	}
	cout<<min(s1,s2);
	return 0;
}
