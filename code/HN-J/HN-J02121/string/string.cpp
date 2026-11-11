#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int s[n+5];
	char a[n+5];
	for(int i=1;i<=n;i++){
		cin>>s[i];
		cin>>a[i];
	}
	int d=0;
	char b[n+5];
	for(int i=n;i>=1;i--){
		for(int j=1;j<=s[i];j++){
			b[i]=a[i];
			d++;
		}
	}
	char ans[n+5];
	int y=d;
	for(int i=1;i<=d;i++){
		ans[i]=b[y];
		y--;
	}
	int num=0;
	for(int i=1;i<=d;i++){
		if(b[i]=!ans[i]){
			num++;
		}
	}
	cout<<num;
	return 0;
}
