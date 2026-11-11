#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
int head=1,tail;
struct S{
	char c;
	int n;
}s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		int nm;
		char cr;
		cin>>nm>>cr;
		if(s[tail].c==cr)s[tail].n+=nm;
		else s[++tail]={cr,nm};
	}
	while(head<tail){
		int minl=min(s[head].n,s[tail].n);
		if(s[head].c!=s[tail].c)ans+=minl;
		s[head].n-=minl;
		s[tail].n-=minl;
		if(s[head].n==0)head++;
		if(s[tail].n==0)tail--;
	}
	cout<<ans;
	return 0;
}
