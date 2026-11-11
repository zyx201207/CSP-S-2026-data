#include <bits/stdc++.h>
using namespace std;
string b,zong,fenq,fenh;
long long acnt=1,bcnt=1,cnt=0,d=1,ji=1;
int n,a[2000020];
int main(){
	long long cnt = 0;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	n=n*2;
	for(int i = 1;i<=n;i++){
		if(i%2==1){
			cin>>a[acnt];
			acnt++;
		}
		else{
			cin>>b[bcnt];
			bcnt++;
		}
	}
	for(int i = 1;i<=acnt;i++){
		cnt+=a[i];
		a[i]=a[i-1]+a[i];
	}	
	for(int i = 1;i<=cnt;i++){
		if(i<=a[d]){
			zong[i]=b[d];
		}
		else{
			d++;
			zong[i]=b[d];
		}
	}
	if(cnt%2==1){
		int fen=cnt/2;
		for(int i = 1;i<=fen;i++){
			fenq[i]=zong[i];
		}
		for(int i = cnt;i>(fen+1);i--){
			fenh[ji]=zong[i];
			ji++;
		}
		cnt = 0;
		for(int i = 1;i<=fen;i++){
			if(fenq[i]!=fenh[i]){
				cnt++;
			}
		}
		cout<<cnt;	
	}
	else{
		int fen=cnt/2;
		for(int i = 1;i<=(fen-1);i++){
			fenq[i]=zong[i];
		}
		for(int i = cnt;i>(fen+1);i--){
			fenh[ji]=zong[i];
			ji++;
		}
		cnt = 0;
		for(int i = 1;i<=fen;i++){
			if(fenq[i]!=fenh[i]){
				cnt++;
			}
		}
		if(zong[fen]!=zong[fen+1]){
			cnt++;
		}
		cout<<cnt;		
	}
	return 0;
}

