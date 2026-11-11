#include<bits/stdc++.h>
using namespace std;

char c[200005];int a[200005],l=1,r,ln,rn,n;long long ans;
void mi(bool flag){
	if(ln>rn){
		ln-=rn;
		if(flag)ans+=rn;
		rn=a[--r];
	}
	else if(ln<rn){
		rn-=ln;
		if(flag)ans+=ln;
		ln=a[++l];
	}
	else{
		if(flag)ans+=ln;
		ln=a[++l];
		rn=a[--r];
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
	}
	r=n;ln=a[1];rn=a[n];
	while(l<r){
		if(c[l]==c[r])mi(0);
		else mi(1);
	}
	cout << ans;
	return 0;
} 
