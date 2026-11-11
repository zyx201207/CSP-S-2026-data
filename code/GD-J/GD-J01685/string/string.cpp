#include <bits/stdc++.h>
using namespace std;
string s;
long long a[200005];
char c[200005];
bool flag=1;
int cnt[27];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	cin>>a[1]>>c[1];
	long long sum=a[1];
	char s=c[1];
	for(int i=2;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		cnt[c[i]]++;
		if(c[i]!=s){
			flag=0;
		}
	}
	bool flag1=1;
	for(int i=0;i<26;i++){
		if(cnt[i]>=1) flag1=false;
	}
	if(flag){
		cout<<0<<endl;
		return 0;
	}
	else
		cout<<sum/2<<endl;
	return 0;
}
