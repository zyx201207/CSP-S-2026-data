#include<bits/stdc++.h>
using namespace std;
int n;
long long m,sta,stan=1,ans,k;
char st,t[100000010];
bool f=true,fm=true,ff=true;
struct ttt{
	int a;
	char c;
} s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i].a>>s[i].c;
	}
	st=s[0].c;
	sta=s[0].a;
	for(int i=1;i<n;i++){
		if(s[i].c!=st){
			f=false;
		}
		if(s[i].a!=sta){
			fm=false;
		}
		if(s[i].a!=1){
			ff=false;
		}
	}
	if(f==true){
		cout<<0<<'\n';
		return 0;
	}
	if(fm==true){
		for(int i=0;i<n/2;i++){
			int j=n-i-1;
			if(s[i].c==s[j].c){
				t[i]=s[i].c;
				t[j]=s[j].c;
			}
			else{
				t[i]=s[i].c;
				t[j]=s[i].c;
				ans++;
			}
		}
		cout<<ans*sta<<'\n';
		return 0;
	}
	for(int i=0;i<n;i++){
		m+=s[i].a;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<s[i].a;j++){
			t[k]=s[i].c;
			k++;
		}
		if(k==m){
			break;
		}
	}
	for(int i=0;i<m/2;i++){
		int j=m-i-1;
		if(s[i].c==s[j].c){
			t[i]=s[i].c;
			t[j]=s[j].c;
		}
		else{
			t[i]=s[i].c;
			t[j]=s[i].c;
			ans++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}         						
