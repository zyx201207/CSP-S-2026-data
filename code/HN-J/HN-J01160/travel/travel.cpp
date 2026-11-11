#include<bits/stdc++.h>
using namespace std;
char a[255],b[255],c[255],d[255],cnt[255];
int n,k;
int main(){
	freopen("travel5.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b;
	cin>>c>>d;
	for(int i=0;i<2;i++) if(a[i]==c[i]) n+=1;
	if(n==2) k+=1,cnt[k]=1;
	else{
		for(int i=1;i<=4;i++) cnt[i]=0;
		cout<<"0000";
		return 0;
	}
	n=0;
	for(int i=0;i<2;i++) if(b[i]==d[i]) n+=1;
	if(n==2) k+=1,cnt[k]=1;
	else{
		for(int i=2;i<=4;i++) cnt[i]=0;
		cout<<"1000";
		return 0;
	}
	n=0;
	int m=int(b[2]);
	int l=int(d[2]);
	if(m>=65&&m<=67&&l>=65&&l<=67||m>=68&&m<=69&&l>=68&&l<=69) k+=1,cnt[k]=1;
	else{
		for(int i=3;i<=4;i++) cnt[i]=0;
		cout<<"1100";
		return 0;
	}
	if(m+1==l||l+1==m) k+=1,cnt[k]=1;
	else{
		for(int i=4;i<=4;i++) cnt[i]=0;
		cout<<"1110";
		return 0;	
	}
	cout<<"1111";
	return 0;
}

