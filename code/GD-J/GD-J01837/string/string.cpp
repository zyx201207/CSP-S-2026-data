#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
char a[N];
int s[N];
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>s[i]>>a[i];
	}
	for (int i=1,k=n;i<=k;){
		if (a[i]==a[k]){
			if (s[i]==s[k]){
				i++;
				k--;
			}
			else if (s[i]>s[k]){
				s[i]-=s[k];
				k--;
			}
			else{
				s[k]-=s[i];
				i++;
			}
		}
		else{
			if (s[i]==s[k]){
				cnt+=s[i];
				i++;
				k--;
			}
			else if (s[i]>s[k]){
				cnt+=s[k];
				s[i]-=s[k];
				k--;
			}
			else{
				cnt+=s[i];
				s[k]-=s[i];
				i++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
