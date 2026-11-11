#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,ans,sum;
struct Node{
	long long h;
	char ch;
}a[N];
void f(){
	long long ls=0,jz;
	for(int i=1;i<=n;i++){
		ls+=a[i].h;
		if(ls==sum/2) return ;
		if(ls>sum/2){
			jz=i;
			break;
		}
	}
	for(int i=n;i>=jz;i--){
		if(i!=jz){
			a[i+1].h=a[i].h;
			a[i+1].ch=a[i].ch;
		}else{
			a[i+1].h=ls-sum/2;
			a[i].h=a[i].h-a[i+1].h;
			a[i+1].ch=a[i].ch;
		}
	}
	n+=1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].h>>a[i].ch;
		sum+=a[i].h;
	}
	f();
	int t=1,w=n;
	long long nt=a[t].h,nw=a[w].h,last=max(nt,nw);
	char ct=a[t].ch,cw=a[w].ch;
	while(nt<sum/2+1||nw<sum/2+1){
		if(ct!=cw) ans+=(last-abs(nt-nw));
		if(nt>nw){
			w--;
			nw+=a[w].h;
			cw=a[w].ch;
		}else if(nt<nw){
			t++;
			nt+=a[t].h;
			ct=a[t].ch;
		}else{
			t++,w--;
			nw+=a[w].h,nt+=a[t].h;
			cw=a[w].ch,ct=a[t].ch;
		}
		if(nt>nw) last=a[t].h;
		else if(nw>nt) last=a[w].h;
		else last=min(a[t].h,a[w].h);
	}
	cout<<ans;
	return 0;
}
