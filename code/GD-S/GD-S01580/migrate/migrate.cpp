#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
string u,v;
int k;
string mul(string n,string m){
	int a[N],b[N],ans[N];
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	memset(ans,0,sizeof ans);
	int l1=n.size(),l2=m.size(),l=l1+l2+1;
	for(int i=1;i<=l1;i++) a[i]=n[l1-i]-'0';
	for(int i=1;i<=l2;i++) b[i]=m[l2-i]-'0';
	for(int i=1;i<=l1;i++){
		for(int j=1;j<=l2;j++) ans[i+j-1]+=a[i]*b[j];
	}
	for(int i=1;i<=l;i++){
		if(ans[i]>9){
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;
			if(i==l) l++;
		}
	}
	int idx=l;
	while(ans[idx]==0&&idx>1) idx--;
	string ANS="";
	for(int i=idx;i>=1;i--) ANS+=char(ans[i]+'0');
	return ANS;
}
string plas(string n,string m){
	int a[N],b[N],ans[N];
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	memset(ans,0,sizeof ans);
	int l1=n.size(),l2=m.size(),l=max(l1,l2)+1;
	for(int i=1;i<=l1;i++) a[i]=n[l1-i]-'0';
	for(int i=1;i<=l2;i++) b[i]=m[l2-i]-'0';
	for(int i=1;i<=l;i++) ans[i]=a[i]+b[i];
	for(int i=1;i<=l;i++){
		if(ans[i]>9){
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;
			if(i==l) l++;
		}
	}
	int idx=l;
	while(ans[idx]==0&&idx>1) idx--;
	string ANS="";
	for(int i=idx;i>=1;i--) ANS+=char(ans[i]+'0');
	return ANS;
}
string plasp(string n,string m){
	int a[N],b[N],ans[N];
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	memset(ans,0,sizeof ans);
	int l1=n.size(),l2=m.size(),l=max(l1,l2)+1;
	for(int i=1;i<=l1;i++) a[i]=n[l1-i]-'0';
	for(int i=1;i<=l2;i++) b[i]=m[l2-i]-'0';
	for(int i=1;i<=l;i++) ans[i]=a[i]-b[i];
	for(int i=1;i<=l;i++){
		if(ans[i]<0){
			ans[i+1]--;
			ans[i]+=10;
			if(i==l) l++;
		}
	}
	int idx=l;
	while(ans[idx]==0&&idx>1) idx--;
	string ANS="";
	for(int i=idx;i>=1;i--) ANS+=char(ans[i]+'0');
	return ANS;
}
string mulp(string n,string m){
	string ANS="0";
	while(n!="0"){
		n=plasp(n,m);
		ANS=plas(ANS,"1");
	}
	return ANS;
}
string logtwo(string n,string m){
	string ANS="0";
	while(n!="1"){
		n=mulp(n,"2");
		ANS=plas("ANS","1");
	}
	return ANS;
}
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>u>>v>>k;
	for(int i=1;i<=k;i++){
		char ch;
		cin>>ch;
		if(ch=='*') cout<<mul(u,v)<<'\n';
		else if(ch=='-') cout<<plasp(u,v)<<'\n';
		else if(ch=='+') cout<<plas(u,v)<<'\n';
		else if(ch=='/') cout<<mulp(u,v)<<'\n'; 
		else cout<<logtwo(u,v)<<'\n';
	}

	return 0;
}
