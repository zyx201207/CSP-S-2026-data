#include<bits/stdc++.h>
using namespace std;
char s[100000010];
int a[200010];
char b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char p;
	int n,m,ans=0;
	long long q=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>p;
		a[i]=m;
		b[i]=p;
		if(q<=100000000){
			for(int j=1;j<=m;j++){
				s[q]=p;
				q++;
			}
		}
		else{
			q+=m;
		}	
	}
	q--;
	if(q>100000000){
		for(int i=1;i<=n;i++){
			if(b[i]!=b[n-i+1]){
				cout<<q;
				return 0; 
			}
		}
		cout<<'0';
		return 0;
	}
	for(int i=1;i<=q/2;i++){
		if(s[i]!=s[q-i+1]){
			ans++;
			s[q-i+1]=s[i];
		}
	}
	cout<<ans;
	return 0;
}
