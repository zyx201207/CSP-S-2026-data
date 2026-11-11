#include<bits/stdc++.h>
using namespace std;
const int Max_n=100000000000005;
char a[Max_n];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n=0,ans=0,tmp=0;
	cin>>n;
	char l[n][2];
	for(int i=0;i<n;i++){
		cin>>l[n][0]>>l[n][1];
	}
	for(int i=0;i<n;i++){
		for(int j=tmp;j<l[i][0];j++){
			a[j]=l[i][1];
		} 
		tmp=tmp+l[i][0];
	}
	cin>>a;
	for(int i=0;i<=n/2;i++){
		if(a[i]=!a[n-1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
