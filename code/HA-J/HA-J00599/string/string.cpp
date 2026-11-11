#include <bits/stdc++.h>
using namespace std;
struct cc{
	int cnt,c0;
}a[200005];
int n,xx;
long long ans,tot;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> xx >> c;
		a[i].cnt=xx,a[i].c0=c;
		tot+=xx;
	}
	long long x=0,xj=0;
	int i=1,j=n;
	while((x<=tot/2||xj<=tot/2)&&i<=j){
		if(a[i].cnt>a[j].cnt){
			x+=a[j].cnt;
			xj+=a[j].cnt;
			if(a[i].c0==a[j].c0) ans+=0;
			else ans+=a[j].cnt;
			a[i].cnt-=a[j].cnt;
			j--;
		}
		else{
			x+=a[i].cnt;
			xj+=a[i].cnt;
			if(a[i].c0==a[j].c0) ans+=0;
			else ans+=a[i].cnt;
			a[j].cnt-=a[i].cnt;
			i++;
		} 
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
