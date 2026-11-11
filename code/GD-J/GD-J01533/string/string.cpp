#include <bits/stdc++.h>
#define let long long
#define str string
#define rt return
using namespace std;
struct cmp{
	let l;
	char c;
}a[200010],b[200010];
let n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(let i = 1;i<=n;i++)cin>>a[i].l>>a[i].c;
	for(let i = n,j = 1;i>=1;i--,j++) b[j] = a[i];
	let i = 1,j = 1,x = a[1].l,y = b[1].l ;
	if(x>y){
		if(a[i].c!=b[i].c) ans+=(x-y);
	}else if(y>x) {
		if(a[i].c!=b[i].c) ans+=(y-x);
	}else if(x==y&&a[i].c!=b[i].c) ans+=x;
	while(1){
		if(i>=n&&j>=n&&x==y) break; 
		if(x<y){
			let len = (y-x);
			if(a[i+1].c!=b[j].c) ans+=len;
			i++;x+=a[i].l;
		}else if(y<x){
			let len = x-y;
			if(b[j+1].c!=a[i].c) ans+=len;
			j++;y+=b[j].l;
		}else if(x == y) {
			let len = min(a[i].l,b[i].l);
			if(b[j].c!=a[i].c) ans+=len;
			i++,j++;
			x+=a[i].l,y+=b[i].l;
		}
	}

		
	
	cout<<ans/2;
	rt 0;
	
}


