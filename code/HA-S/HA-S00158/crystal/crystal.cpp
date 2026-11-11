#include <bits/stdc++.h> 
using namespace std;

int theN,theleft,theright,themid,theans;
long long theM,theA[500005],thesumofpre[500005];

bool tocheck(int thecheckedone){
	if(thecheckedone==1)return false;
	for(int i=thecheckedone;i<=theN;i++){
		long long tomaketheneed=(theA[i]*(thecheckedone-1))-(thesumofpre[i-1]-thesumofpre[i-thecheckedone]);
		if(tomaketheneed<=theM)return true;
	}
	return false;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>theN>>theM;
	for(int i=1;i<=theN;i++)cin>>theA[i];
	theleft=1;theright=theN-1;
	sort(theA+1,theA+theN+1);
	for(int i=1;i<=theN;i++)thesumofpre[i]=thesumofpre[i-1]+theA[i];
	while (theleft<=theright){
		themid=(theleft+theright)/2;
		if(tocheck(themid)){
			theans=themid;
			theleft=themid+1;
		}
		else theright=themid-1;
	}
	cout<<theans;
	return 0;
}
