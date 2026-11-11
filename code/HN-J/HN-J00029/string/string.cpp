#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000006],n;
char b[100006];
int check(string x){
	int ans=0;
	for(int i=0;i<=x.size()/2;i++){
		if(x[i]!=x[x.size()-i])ans++;
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long x=0;
	while(n--){
		x++;
		cin>>a[x];
		cin>>b[x];
		if(b[x]==b[x-1]){
			x--;
			a[x]+=a[x+1];
		}
	}
	for(int i=1;i<=x;i++){
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	cout<<check(s);
	return 0;
}
