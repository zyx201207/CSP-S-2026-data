#include<bits/stdc++.h>
using namespace std;
int n,a[100000000],m;
struct zzz{
	int ch,i,mch;
}b[100000000];
bool px(zzz x,zzz y){
	if(x.mch ==y.mch )return x.i >y.i ;
	return abs(x.mch )<abs(y.mch ); 
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}sort(a,a+n);
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			b[i].ch +=a[i]-a[j];
		}
	}for(int i=1;i<=n;i++){
		b[i].i =i;
		b[i].mch =m-b[i].ch ;
	}
	sort(b+1,b+n,px);
	cout<<b[1].i +1;
	return 0;
} 
