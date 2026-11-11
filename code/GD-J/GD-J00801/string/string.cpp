#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],b[200010],ans;
char ch[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		b[i]=b[i-1]+a[i];
	}
	if(b[n]<=100000){
		string w;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=a[i];j++)w+=ch[i];
		for(int i=0;i<=b[n]/2;i++){
			if(w[i]!=w[n-i+1]){
				ans++;w[n-i+1]=w[i];
			}
		}
		cout<<ans;return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(ch[i]!=ch[j]&&(b[j]>=b[n]-b[i]||b[j-1]<=b[n]-b[i-1]))ans+=min(b[j],b[n]-b[i-1])-max(b[j-1],b[n]-b[i]);
		}
	}
	cout<<ans;
	return 0;
}
