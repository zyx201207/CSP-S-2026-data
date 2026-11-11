#include <bits/stdc++.h>
#define int long long
using namespace std;
long long n,m,a[500010],aa=-1000000000,ia=1000000000;
void solv1(){//1-7
	int ji=0,ans=0,npc=0,an=0;
	for(int i=ia;i<=aa;i++){
		ji=0;
		for(int j=1;j<=n;j++){
			if(a[j]<=i){
				ji=j;
			}else{
				break;
			}
		}
		ans=0;
		npc=0;
		for(int j=ji;j>=1;j--){
			if(npc+i-a[j]<=m){
				npc+=i-a[j];
				ans++;
			}else{
				break;
			}
		}
		an=max(an,ans);
//		cout<<ans<<" "<<i<<endl;
	}
	cout<<an;
}
void solv2(){//8-9
	int ji=0,ans=0,npc=0,an=0;
	for(int i=a[1];i<=a[n];i++){
		ji=0;
		for(int j=1;j<=n;j++){
			if(a[j]<=i){
				ji=j;
			}else{
				break;
			}
		}
		ans=0;
		npc=0;
		for(int j=ji;j>=1;j--){
			if(npc+i-a[j]<=m){
				npc+=i-a[j];
				ans++;
			}else{
				break;
			}
		}
		an=max(an,ans);
//		cout<<ans<<" "<<i<<endl;
	}
	cout<<an;
}
void solv3(){//13-15
	int ans=0,npc=0;
	for(int i=1;i<=n;i++){
		if(npc<=m){
			ans++;
			npc+=i;
		}else{
			break;
		}
	}
	cout<<ans;
}
void solv4(){//16-18
	int ans=0,npc=0;
	for(int i=n;i>=1;i--){
		if(npc+a[n]-a[i]<=m){
			ans++;
			npc+=a[n]-a[i];
		}else{
			break;
		}
	}
	cout<<ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		aa=max(aa,a[i]);
		ia=min(ia,a[i]);
	}
	bool che=true;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=a[2]-a[1]){
			che=false;
		}
	}
	sort(a+1,a+n+1);
	if(aa-ia<=1000&&n<=5000){
		solv1();
	}else if(n<=5000){
		solv2();
	}else if(che){
		if(a[2]-a[1]==1){
			solv3();
		}else{
			solv4();
		}
	}else{
		solv2();
	}
	return 0;
}
