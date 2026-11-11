#include <bits/stdc++.h>
using namespace std;
struct st{
	int h,t;
	char c;
};
st a[200005];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string s="";
	long long ans=0;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		a[i].c=c;
		a[i].h=a[i-1].t+1;
		a[i].t=a[i].h+x-1;
	}
	int ln=1,rn=n;
	for(int i=1;i<=n;i++){
		if(a[ln].c!=a[rn].c){
			if(a[ln].t-a[ln].h+1>=a[rn].t-a[rn].h+1){
				ans+=a[rn].t-a[rn].h+1;
				a[ln].h+=a[rn].t-a[rn].h+1;
				rn--;
			}else{
				ans+=a[ln].t-a[ln].h+1;
				a[rn].t-=a[ln].t-a[ln].h+1;
				ln++;
			}
		}else{
			if(a[ln].t-a[ln].h+1>=a[rn].t-a[rn].h+1){
				a[ln].h+=a[rn].t-a[rn].h+1;
				rn--;
			}else{
				a[rn].t-=a[ln].t-a[ln].h+1;
				ln++;
			}
		}
		if(ln>rn) break;
	}
	cout<<ans;
	return 0;
}