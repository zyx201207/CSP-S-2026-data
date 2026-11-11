#include<bits/stdc++.h>
using namespace std;
char s[20005];
long long num[20005];
long long hui(int l) {
	long long ans=0,cnt=0;
	for(int i=1; i<=l; i++) {
		if(s[i]!=s[l-i+1]) {
			if(num[i]>=num[l-i+1]) {
				int cha=num[i]-num[l-i+1];
				s[l-i+1]=s[i];
				ans+=num[i];
				num[l-i+1]-=cha;
				num[l-i]+=cha;
			} else {
				int cha=num[l-i+1]-num[i];
				s[i]=s[l-i+1];
				ans+=num[l-i+1];
				num[i]-=cha;
				num[i+1]+=cha;
			}
		}else{
			if(num[i]!=num[l-i+1]){
			}
		}
	}
	return ans;
}
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>num[i-cnt]>>s[i-cnt];
		if(s[i-cnt]==s[i-1-cnt]) {
			num[i-cnt-1]+=num[i-cnt];
			num[i-cnt]=0;
			s[i-cnt]=' ';
			cnt++;
		}
	}
	cout<<hui(n-cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

