/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum,n;
string s;
char a[200010];
ll num[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char x;
		ll y;
		cin>>y>>x;
		a[i]=x;
		num[i]=y;
	}
	for(int i=1;i<=floor(n*1.0/2);i++){
		
		if(a[n-i+1]!=a[i]){
			if(i!=ceil(n*1.0/2)){
				sum+=max(num[i],num[n-i+1]);
				a[i]=a[n-i+1];
				if(max(num[i],num[n-i+1])==num[i]){
					num[n-i]-=abs(num[i]-num[n-i+1]);
				}else{
					num[i+1]-=abs(num[n-i+1]-num[i]);
				}
			}else{
				sum+=min(num[i],num[n-i+1]);
			}
		}else if(num[i]!=num[n-i+1]&&!(i==ceil(n*1.0/2)||(i==floor(n*1.0/2)&&a[i+1]==a[i]))){
			sum+=abs(num[i]-num[n-i+1]);
			if(max(num[i],num[n-i+1])==num[i]){
				num[n-i]-=abs(num[i]-num[n-i+1]);
			}else{
				num[i+1]-=abs(num[n-i+1]-num[i]);
			}
		}
	}
	cout<<sum;
	return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum,n;
string s;
char a[200010];
ll num[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		char x;
		cin>>x;
		for(int i=1;i<=k;i++){
			s+=x;
		}
	}
	ll l=s.size();
	s=' '+s;
	for(int i=1;i<=floor(l/2);i++){
		if(s[l-i+1]!=s[i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}

