#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	int s[100005];
	char q[100005];
	int n;
	int cnt=0;
	int cnt1=1,cnt2=0;
	//string x;
	string x[10005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		cin>>q[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s[i];j++){
			cnt++;
			//x+=q[i];
			x[cnt1]=q[i];
			cnt1++;
		}
	}
	int w=1;
	while(cnt1-w==1||cnt1==w){
		if(x[w]!=x[cnt1]){
			cnt2++;
			w++;
			cnt1--;
		}
		else{
			cnt1--;
		}
	}
	
	cout<<cnt2;
	return 0;
}
