//GZ-J00662 都匀第十中学 郑杰康 
#include<bits/stdc++.h>
using namespace std;
string a;
char c,d[30],th;
int n,t,tp,mina=0x3F3F3F3F;
void dg(int s,string b,char bl,int ss){
	tp=0;
	for(int i=0,j=b.size()-1;i<b.size()/2;i++,j--){
		if(b[i]==b[j])tp+=1;
		else break;
	}
	if(tp==b.size()/2){
		mina=min(mina,ss);
		return ;
	}
	if(s==0)return ;
	for(int i=0;i<b.size();i++){
		if(b[i]!=bl){
			th=b[i];
			b[i]=bl;
			dg(s-1,b,bl,ss);
			b[i]=th;
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t>>c;
		d[int(c)-96]=1;
		for(int j=0;j<t;j++){
			a+=c;
		}
	}
	for(int i=0;i<=a.size();i++){
		for(int j=1;j<=26;j++){
			if(d[j]!=0)dg(i,a,a[j],i);
		}
	}
	cout<<mina;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
