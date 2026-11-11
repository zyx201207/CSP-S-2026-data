//GZ-J00278 章茂辰 贵阳市南明区李端棻中学
#include<bits/stdc++.h>
using namespace std;


long long n;
long long sum;


string S;
int main(){
	ios::sync_with_stdio((0));
	cin.tie((0));
	cout.tie((0));
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,a;
		cin>>x>>a;
		for(int j=1;j<=x;j++){
			S+=a;
		}

	}
	int WS=S.size();

	if(WS%2!=0){
		WS=WS-1;
	}

	for(int i=0;i<WS/2;i++){
		if(S[i]!=S[WS-i-1]){
			sum++;
		}
	} 
	cout<<sum;
	return 0;
}

