#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long 
int n,ans;
int const N = 2e5+5;
int a[N],t;
char c[N]; 
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n; 
	for(int i=1;i<=n;i++){
		int da;
		char dc; 
		cin>>da>>dc;
		if(dc == c[t]) a[t] += da;
		else t++,a[t]=da,c[t]=dc; 
	}
	/*for(int i=1;i<=t;i++){
		cout<<a[i]<<" "<<c[i]<<endl;
	}*/ 
	for(int ia=1,ja=t,iz=1,jz=a[t];ia<=ja;){
		//cout<<"ia="<<ia<<" ja="<<ja<<" iz="<<iz<<" jz="<<jz<<endl; 
		if(ia==ja && iz>=jz) break;
		int p=min(a[ia]-iz+1,jz);
		if(ia!=ja){
			if(c[ia]!=c[ja]){
			ans += p;
			}
			iz += p; 
			jz -= p;
			if(iz>a[ia]) iz-=a[ia],ia++;
			if(jz<1) ja--,jz+=a[ja];
		}else{
			break; 
		} 
	}
	cout<<ans; 
	return 0;
}
