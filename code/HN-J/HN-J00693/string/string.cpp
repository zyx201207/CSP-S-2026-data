#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin>>n;
	long long a[n+1];
	char d[n+1];
	for(int y=1;y<=n;y++){
		cin>>a[y]>>d[y];
	}
	int sum=0;
	for(int y=1;y<=n;y++){
		sum+=a[y];
}
	char c[sum];
	int ans=1;
	for(int h=1;h<=n;h++){
		for(int f=1;f<=a[h];f++){
			c[ans]=d[h];
			ans++;
		}
	}
	long long zhans=0;
	long long ha=1;
	for(int j=sum;j>=ha;j--){
		if(c[ha]!=c[j]&&ha!=j){
			zhans++;
			ha++;
		}
	}
	cout<<zhans;
	return 0;
}
