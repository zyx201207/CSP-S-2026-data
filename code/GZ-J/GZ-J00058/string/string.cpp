//GZ-J00058,ÈÎ²ªÓî£¬Ê®¾ÅÖĞ 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
char a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x,sum=0;
	char b;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> x >> b;
		sum+=x;
		for(int i=0;i<x;i++){
			a[i]=b;
		}
	}
	int ans=0;
	for(int i=0;i<sum/2;i++){
		if(a[i]!=a[sum+1-i])ans++;
	}
	cout << ans;
	return 0;
}
