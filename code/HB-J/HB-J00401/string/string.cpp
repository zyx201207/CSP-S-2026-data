#include<iostream>
using namespace std;

int n;
long long len=0,nowl=1,nowr,ptr=1,lst=0,siz[200005],enddl[200005],enddr[200005],as=0,chr[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	enddl[0]=0;
	enddr[0]=-1;
	enddl[n+1]=-1;
	enddr[n+1]=0;
	for(int i=1;i<=n;i++){
		char cc;
		cin>>siz[i]>>cc;
		chr[i]=cc;
		len+=siz[i];
		enddl[i]=enddl[i-1]+siz[i];
	}
	nowr=n;
	for(int i=n;i>=1;i--) enddr[i]=enddr[i+1]+siz[i];
	//for(int i=1;i<=n;i++) cout<<siz[i]<<" "<<chr[i]<<" "<<enddl[i]<<" "<<enddr[i]<<"\n";
	len>>=1;
	while(ptr<=len){
		if(ptr==-1) break;
		if(chr[nowl]!=chr[nowr]) as+=ptr-lst;
		lst=ptr;
		int ln,rn;
		if(enddl[nowl]!=ptr) ln=nowl;
		else ln=nowl+1;
		if(enddr[nowr]!=ptr) rn=nowr;
		else rn=nowr-1;
		//cout<<ptr<<ln<<rn<<nowl<<nowr<<"\n";
		if(enddl[ln]<enddr[rn]){
			ptr=enddl[ln];
			nowl=ln;
			if(ptr>enddr[nowr]) nowr--;
		}
		else{
			ptr=enddr[rn];
			nowr=rn;
			if(ptr>enddl[nowl]) nowl++;
		}
	}
	cout<<as;
	return 0;
}
