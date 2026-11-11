#include <bits/stdc++.h>

using namespace std;
int a,b,c,d,e=1,f;
const int N=1e7+10;
int n[N],x[N],x1[N],x2[N];
int aaa(int y){
	for(int i=1;i<=y;i++){
		if(x[i]==n[y]){
			c=i;
			return 1;
		}
	}
	return 0;
}
int bbb(int y){
	if(e==1){
		return 0;
	}
	for(int i=1;i<y;i++){
		if(x2[i]==n[y]){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out ","w",stdout);
	cin >> a >> b;
	for(int i=1;i<=a;i++){
		cin >> n[i];
		if(bbb(i)){
			
		}else{
			x2[e]=n[i];
			e++;
		}
	}
	for(int i=1;i<=a;i++){
		d=1;
		for(int j=i;j<=a;j++){
			if(aaa(j)){
				f=c;
				for(;c<=d;c++){
					x[c]=0;
				}
				x[f]=n[j];
				d=f;
			}else{
				x[d]=n[j];
			}
			d++;
		}
		d--;
		for(int j=1;j<=d;j++){
			x1[x[j]]++;
		}
		for(int j=1;j<=a;j++){
			x[i]=0;
		}
	}
	e--;
	sort(x2+1,x2+1+e);
	for(int i=1;i<=b;i++){
		cout << x1[x2[i]] <<" ";
	}
	return 0;
}
//Trick||Treat!
