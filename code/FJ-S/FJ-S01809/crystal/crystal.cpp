#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long s,n,ans=0,mn[21],sn1[21],sn[21],i=0,msun=0,a;
char m[21];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	memset(m,'0',sizeof(m));
	cin>>n;
	cin>>m;
	for(i=1;i<=n;i++){
		cin>>a;
	}
	int lm=strlen(m);
	lm=lm-1;
	s=n*(n-1)/2;
	while(s!=0){
		sn1[i]=s%10;
		s/=10;
		i++;
	}
	int ls=i-1;
	int j=0;
	for(i=ls;i>=0;i++){
		sn[j]=sn1[i];
		j++;		
	}
	for(i=0;i<=lm;i++){
		mn[i]=m[i]-48;
	}
	if(ls<lm){
		cout<<n;
		fclose(stdin),fclose(stdout);
		return 0;
	}
	else if(ls==lm){
		for(i=0;i<=lm;i++){
			if(sn[i]>mn[i]) break;
			else if(sn[i]<mn[i]||i==lm){
				cout<<n;
				fclose(stdin),fclose(stdout);
				return 0;
			}
		}
	}
	int x=1;
	for(i=lm;i>=0;i++){
		msun=mn[i]*x;
		x=x*10;
	}
	int y=1;
	while(msun>=y){
		msun-=y;
		y++;
		ans++;
	}
	cout<<ans;
	fclose(stdin),fclose(stdout);
	return 0;
}
