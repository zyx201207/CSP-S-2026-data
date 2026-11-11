#include <bits/stdc++.h>
using namespace std;

int n,cnt=0;
long long a[10000001];
char b[10000001];
bool j=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	string c,s;
	for(int i=1;i<=n;i++) for(int j=0;j<a[i];j++) c+=b[i];
	int mid=c.size()/2;
	s=c.substr(0,mid);
	int v=0;
	for(int i=c.size()-1;i>mid-1;i--){
		if(c[v]!=c[i]) cnt++;
		v++;
	}
	cout<<cnt<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
