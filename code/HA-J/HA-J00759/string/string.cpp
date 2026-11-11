#include<bits/stdc++.h>
using namespace std;
char b[10020];
int n,a,cnt,ans=0;
char s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a >> s;
		for(int j=1;j<=a;j++){
			b[j]+=s;
		}
		cnt+=a;
		
	}

	for(int i=1;i<=cnt;i++){
		if(b[i]!=b[cnt]){
			ans++;
			cnt--;
		}else{
			cnt--;
		}
	}
	cout <<ans;
	return 0;
}
