#include<bits/stdc++.h>
using namespace std;
int n;
int s[200010];
char c[200010];
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>c[i];
	}
	int end=n;
	for(int i=1;i<=n;i++){
		int cnt=s[i];
		int su=end;
		for(int j=end;j>=1;j--){
			if(su<i) break;
			if(cnt>=s[j]){
				su--;
				cnt-=s[j];
				if(c[j]==c[i]) continue;
				else sum+=s[j];
			}else{
				s[j]-=cnt;
				if(c[j]==c[i]){
					break;
				}else{
					sum+=cnt;
					break;
				}
			}
		}
		end=su;
		if(end<i) break;
	}
	cout<<sum;
	return 0;
}
