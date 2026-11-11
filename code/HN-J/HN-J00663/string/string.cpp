#include<bits/stdc++.h>
using namespace std;
struct df{
	long long start;
	long long end;
	char abc;
};
int n;
df s[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	long long as=0;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		as+=x;
		s[i].abc=y;
		s[i].start=s[i-1].end+1;
		s[i].end=as;
	}
	long long bg=as;
	bg/=2;
	if(as%2==1)bg++;
	int ss=0,cnt=0;
	for(int i=bg+1;i<=as;i++){
		while(!(s[ss].start<=i&&s[ss+1].start>=i))ss++;
		long long ai=as-i+1;
		int xs=ss-1;
		while(s[xs].end>=ai)xs--;
		xs++;
		if(s[xs].abc!=s[ss].abc)cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
