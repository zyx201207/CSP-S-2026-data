#include<bits/stdc++.h>
using namespace std;
int n;
long long s[200010],ans,k,h;
char c[200010];
bool f=false;
string w;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&s[i]);
		cin>>c[i];
		h+=s[i];
	}
	for(int i=2;i<=n;i++){
		if(c[i]!=c[i-1]) f=true;
	}
	if(!f){
		cout<<0;
		return 0;
	}
	if(n*h<1000000){
		int t=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=s[i];j++){
				w[t]=c[i];
				t++;
			}
		}
		for(int i=0;i<t/2;i++){
			if(w[i]!=w[t-i-1]) ans++;
		}
		printf("%lld",ans);
		return 0;
	}
	else{
		for(int i=1,j=n;i<=j;i++,j--){
			if(c[i]!=c[j]){
				k+=max(s[i],s[j]);
			}
		}
		printf("%lld",k);
		return 0;
	}
	return 0;
}
