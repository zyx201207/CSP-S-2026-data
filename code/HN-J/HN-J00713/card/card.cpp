#include<bits/stdc++.h>//好题，绝对是好题，函数调用那题的trick的绝妙的应用。 
using namespace std;//感觉略难于2025CSP-J。 
int n,m,a[514514],b[514514],r[514514],ans[514514],dy[514514],ad[514514];//fc故意找茬的来了... 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=n;i>=1;--i){
		dy[i]=1;
		if(b[a[i]]){
			r[i]=b[a[i]];
		}else{
			if(i!=n)
			r[i]=i+1;
			ad[i]=a[i];
		}
		b[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
//		cout << i << ' ' << dy[i] << '\n';
		if(r[i]){
			dy[r[i]]+=dy[i];
		}
		if(ad[i]){
			ans[ad[i]]+=dy[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
} 
