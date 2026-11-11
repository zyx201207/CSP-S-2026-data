#include<bits/stdc++.h>
using namespace std;
int n;
int a[200001],cnt=0;
char c[200001];
long long d[100000000]={};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	int g[200001]={},h=0;
	for(int i=1;i<=n;i++){
		if(a[1]==a[i]){
			g[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(g[i]==0){
			h=1;
		}
	}
	if(h==1){
		int de=n,sum=0;
		for(int i=1;i<=de;i++){
			if(c[i]!=c[de]){
				sum++;
			}
			de--;
		}
		cout<<sum*a[1];
		return 0;
	}else{
		int b=1,de=cnt;
		char s[cnt];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				s[b]=c[i];
				b++;
			}
		}
		for(int i=1;i<=de;i++){
			if(s[i]==s[de]){
				d[i]=0;
			}else{
				d[i]=1;
			}
		}
		int f=0;
		if(cnt%2==1){\
			for(int i=1;i<=cnt%2+2;i++){
				if(d[i]==1){
					f=1;
				}
			}
			if(f==0){
				cout<<"0";
				return 0;
			}
		}else{
			for(int i=1;i<=cnt%2+1;i++){
				if(d[i]==1){
					f=1;
				}
			}
			if(f==0){
				cout<<"0";
			}
		}
		int sum=0;
		for(int i=1;i<=de;i++){
			if(s[i]!=s[de]){
				sum++;
			}
			de--;
		}
		cout<<sum;
	}
	return 0;
}
