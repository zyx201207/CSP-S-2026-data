#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string sa,sb,ta,tb;
	cin>>sa>>sb>>ta>>tb;
	char s=sb[2],t=tb[2];
	bool flaga,flagb,flagc,flagd;
	flaga=flagb=flagc=flagd=false;
	if(sa[0]==ta[0]&&sa[1]==ta[1]) flaga=true;
	if(sb[0]==tb[0]&&sb[1]==tb[1]&&flaga) flagb=true;
	int sk=s-'A',tk=t-'A';
	if(((sk>2&&tk>2)||(sk<=2&&tk<=2))&&flagb&&flaga){
		flagc=true;
	}
	if(flagc&&abs(sk-tk)==1&&flaga){
		flagd=true;
	}
	cout<<flaga<<flagb<<flagc<<flagd;
	return 0;
}