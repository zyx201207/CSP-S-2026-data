//GZ-00387 贵阳市南明区华麟学校 杨博麟 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,cnt;
struct node{
	char a;
	long long num;
} s[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i].num>>s[i].a;
	int l=1,r=n;
	while(l<=r){
		char ua=s[l].a,va=s[r].a;
		long long un=s[l].num,vn=s[r].num,mi=min(un,vn);
		if(ua!=va){
			cnt+=mi;
			//cout<<l<<' '<<r<<' '<<un<<' '<<vn<<"\n";
		}
		un-=mi,vn-=mi;
		s[r].num=vn,s[l].num=un;
		if(un==0) l++;
		if(vn==0) r--;
	}
	cout<<cnt;
	return 0;
}

