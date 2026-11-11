#include<bits/stdc++.h>
using namespace std;
long long n,a[100001],ans=0;
char b[100001];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
			cnt++;
			s[cnt]=b[i];
		}
	}
	if(cnt%2==0){
		int i=cnt/2;
		int j=cnt/2+1;
		while(1){
			if(s[i]!=s[j]){
				ans++;
			}
			i--;
			j++;
			if(i==1) break;
			if(j==cnt) break;
		}
		cout<<ans;
		return 0;
	}
	else{
		int i=cnt/2;
		int j=cnt/2+2;
		while(1){
			if(s[i]==s[j]){
				ans++;
			}
			i--;
			j++;
			if(i==1) break;
			if(j==cnt) break;
		}
		cout<<ans;
		return 0;
	}
}	
