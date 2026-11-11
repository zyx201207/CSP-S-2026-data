#include<bits/stdc++.h>
using namespace std;
char c[200005];
int a;
string s;
unsigned long long l;
unsigned long long ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	int n;
	cin>>n;
	if(n==1) {
		cout<<0;
		return 0;
	}
	if(n==2){
		int d,e;
		char f,g;
		cin>>d>>f>>e>>g;
		if(f==g){
			cout<<0;
			return 0;
		}else if(d==e){
			cout<<d;
			return 0;
		}else{
			for(int i=0;i<d+e;i++){
				if(i<d)s[i]=f;
				else s[i]=g;
			}
			int an=0;
			for(int i=0;i<d+e;i++){
				if(s[i]!=s[d+e-i-1])ans++;
			}
			cout<<an/2;
			return 0;
		}
		
	}	
	if(n>10&&n<=2000){
		for(int i=1;i<=n;i++){
			cin>>c[i];
		}
		int an=0;
		for(int i=1;i<=n;i++){
			if(c[i]!=c[n+1-i])an++;
			
		}
		cout<<an/2;
		return 0;
	}
	if(n>2000&&n<=200000){
		for(int i=1;i<=n;i++){
			cin>>c[i];
		}
		int an=0;
		for(int i=1;i<=n;i++){
			if(c[i]!=c[n+1-i])an++;
		}
		cout<<an/2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a>>c[i];
		for(int j=l;j<=a-1;j++){
			s[j]=c[i];
		}
		l+=a;
	}

	ans=0;
	for(int i=0;i<l;i++){
		if(s[i]!=s[l-i-1])ans++;
	}
	cout<<ans/2;
	return 0;
}
