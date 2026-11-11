#include<bits/stdc++.h>
using namespace std;
char ans[11111111];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int t=0;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int i=t+1;i<=t+a;i++){
			ans[i]=c;
		}
		t+=a;
	}
	int cnt=0;
	if(t%2!=0){
		int j=t/2+1;
		for(int i=1;i<=t/2;i++){
			if(ans[j+i]!=ans[j-i]){
				cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}
	int j=t/2;
	int k=t/2+1;
	for(int i=0;i<=t/2;i++){
		if(ans[j-i]!=ans[k+i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
