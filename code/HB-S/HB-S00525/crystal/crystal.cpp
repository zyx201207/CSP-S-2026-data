#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a;
ll b,c[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	sort(c+1,c+a+1);
	ll wow=1,owo=0,ovo=0;
	int l=0,r=1;
	while(r<a){
		ovo++;
		owo=owo+(c[r+1]-c[r])*ovo;
		while(owo>b&&l<r){
			l++;
			owo=owo-(c[r+1]-c[l]);
			ovo--;
		}
		if(ovo+1>wow) wow=ovo+1;
		r++;
	//	cout<<owo<<" ";
	}
	cout<<wow;
	return 0;
}
