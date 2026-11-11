#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int N=1e6;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1) cout<<0;
	else {
		int a,l,ans=0,k=1;char c;
		string b,lt,rt;
		for(int j=1;j<=n;j++){
			cin>>a>>c;l+=a;
			for(int i=1;i<=a;i++,k++) b[k]=c;
		}
		for(int i=1;i<=l/2;i++) lt[i]=b[i];
		for(int i=1,j=l;i<=l/2;i++,j--) rt[i]=b[j];
		for(int i=1;i<=l/2;i++){
			if(lt[i]!=rt[i]) ans++;
		}
		cout<<ans;			
	}
	return 0;
}
