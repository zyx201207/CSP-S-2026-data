#include<bits/stdc++.h>
using namespace std;
char a[1000000001]={};
int ss=0;
void hw(int l,int r){
	int x=r-l;
	while(x==1||x==0){
		if(a[r]!=a[l]){
			a[r]=a[l];
			ss++;
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int ans=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		int m;
		cin>>m;
		char s;
		cin>>s;
		for(int j=ans;j<ans+m;j++){
			a[j]=s;
		}
		ans+=m;
	}
	hw(1,ans);
	cout<<ss+2;
	return 0;
}

