#include <bits/stdc++.h>
using namespace std;
struct str{
	long long a;
	string b;
}p[200005];
string s="0";
long long n,num,q[200005];
bool flag=1;
bool cmp(long long m,long long n){
	return m>n;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].a>>p[i].b;
		q[i]=p[i].a;
	}
	sort(q+1,q+n+1,cmp);
	long long x=q[1];
	for(int i=2;i<=n;i++){
		if(x!=q[i]){
			flag=0;
			break;
		}
	}
	if(!(flag)){
		x=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=p[i].a/x;j++){
			s+=p[i].b;
		}
	}
	int l=s.size();
	if(n%2==0){
		for(int i=1;i<=(l-1)/2;i++){
			if(s[i]==s[l-i]){
				continue;
			}
			else{
				num++;
			}
		}
	}
	else{
		for(int i=1;i<=(l-1)/2;i++){
			if(s[i]==s[l-i]){
				continue;
			}
			else{
				num++;
			}
		}
	}
	if(x!=1){
		cout<<num*x;
		return 0;
	}
	cout<<num;
	return 0;
}
