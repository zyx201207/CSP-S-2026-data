#include <bits/stdc++.h>
using namespace std;
struct I{
	int a;
	char c;
}A[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	long long cnt=0;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin >> A[i].a >> A[i].c;
		sum+=A[i].a;
	}
	vector<char> v(sum+1,' ');
	v[1]=A[1].c;
	int x=1;
	for(int i=1;i<n;i++){
		v[x+A[i].a]=A[i+1].c;
		x+=A[i].a;
	}
	char ch=v[1];
	for(int i=2;i<=sum;i++){
		if(v[i]==' ')v[i]=ch;
		else ch=v[i];
	}
	for(int l=1,r=sum;l<=r;l++,r--){
		if(v[l]!=v[r])cnt++;
	}
	cout << cnt << endl;
	return 0;
}
