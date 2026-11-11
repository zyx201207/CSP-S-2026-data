#include <bits/stdc++.h>
using namespace std;
int ans[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	char ch[200005][32];int b1[200005],lin=0;
	int a,b;cin>>a>>b;
	for (int i=0;i<a;i++){
		int a1;cin>>a1;
		bitset<32> bs(a1);
		string s="op";
		s=bs.to_string();
		b1[lin]=a1;
		for (int j=0;j<32;j++){
			ch[lin][j]=s[j];
		}lin++;
	}
	
	for (int i=0;i<32;i++){
		int cnt=0;
		for (int j=0;j<lin;j++){
			if (ch[j][i]=='1'&&ans[j]==0){
				cnt++;
			}
		}if (cnt>=b){
			for (int j=0;j<lin;j++){
				if (ch[j][i]=='0'){
					ans[j]=1;
				}
			}
		}
	}
	int pos=0;
	for (int i=0;i<lin;i++){
		if (ans[i]==0){
			pos=b1[i];break;
		}
	}
	for (int i=0;i<lin;i++){
		if (ans[i]==0){
			pos=pos&b1[i];
		}
	}cout<<pos;
	return 0;
}
