#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],cnt,ans;
char c[200005];
string s;
bool f=false;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		while(a[i]--){
			s[cnt]=c[i];
			cnt++;
		}
	}
	if(cnt%2==1){
		cnt/=2;
		f=true;
	}else{
		cnt/=2;
		cnt--;
	}
	for(int i=cnt;i>=0;i--){
		if(f){
			if(i==cnt){
				continue;
			}else{
				if(s[2*cnt-i]!=s[i]){
					ans++;
				}
			}
		}else{
			if(s[2*cnt-i+1]!=s[i]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
