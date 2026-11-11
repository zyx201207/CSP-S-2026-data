#include<bits/stdc++.h>
using namespace std;
struct zfc{
	long long a;
	char c;
}c[200005],s1,s2;
int n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i].a>>c[i].c;
	}
	long long ans=0;
	s1.a=c[1].a;
	s1.c=c[1].c;
	s2.a=c[n].a;
	s2.c=c[n].c;
	for(int l=1,r=n;l<r;){
		long long cnt=min(s1.a,s2.a);
		if(s1.c==s2.c){
			s1.a-=cnt;
			s2.a-=cnt;
		}else{
			ans+=cnt;
			s1.a-=cnt;
			s2.a-=cnt;
		}
		if(s1.a==0){
			l++;
			s1.a=c[l].a;
			s1.c=c[l].c;
		}
		if(s2.a==0){
			r--;
			s2.a=c[r].a;
			s2.c=c[r].c;
		}
	}
	cout<<ans;
	return 0;
}
