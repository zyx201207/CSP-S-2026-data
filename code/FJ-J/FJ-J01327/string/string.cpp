#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long ans;
string s;
struct T{
	long long num;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
	}
	int l=1,r=n;
	while(l+1<=r){
		if(a[l].num>a[r].num){
			if(a[l].c!=a[r].c)	ans+=a[r].num;
			a[l].num-=a[r].num;
			r--;
		}else if(a[l].num<a[r].num){
			if(a[l].c!=a[r].c)	ans+=a[l].num;
			a[r].num-=a[l].num;
			l++;
		}else if(a[l].num==a[r].num){
			if(a[l].c!=a[r].c)	ans+=a[l].num;
			r--;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
