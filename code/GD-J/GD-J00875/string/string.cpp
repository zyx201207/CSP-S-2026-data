#include<bits/stdc++.h>
using namespace std;
string ss;
long long res=0;
int n;
long long ans=0;
long long s[200005];
char ch[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char b;
		cin>>a>>b;
		s[i]=a;
		ch[i]=b;
		res++;
	}
	
	long long r=res;
	long long l=1;
	while(l<r){
		if(s[r]!=0&&s[l]!=0&&ch[r]!=ch[l]){
			ans++;
			s[r]--;
			s[l]--;
			if(s[r]!=0&&s[l]!=0){
				continue;
			}else if(s[r]==0&&s[l]!=0){
				r--;
			}else if(s[r]!=0&&s[l]==0){
				l++;
			}else if(s[r]==0&&s[l]==0){
				r--;
				l++;
			}
		}else if(s[r]!=0&&s[l]!=0&&ch[r]==ch[l]){
			long long vec=min(s[r],s[l]);
			if(vec==s[r]&&vec!=s[l]){
				r--;
			}else if(vec!=s[r]&&vec==s[l]){
				l++;
			}else if(vec==s[r]&&vec==s[l]){
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
