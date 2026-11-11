#include<bits/stdc++.h>
using namespace std;
int n,m,d=-1,dd=-1;
int a[99999],b[99999],c[9999][9999];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d=max(d,a[i]);
		if(m!=1){
		int aa=a[i],aaa=1,aaaa=0;
		while(aa/2!=0){
			aa/=2;aaa*=2;
			aaaa++;
		}
		dd=max(dd,aaaa+1);
		int aaaaa=aaaa;
		while(aaa!=0){
			if(a[i]>=aaa){
				a[i]-=aaa;
				c[i][aaaa+1]=1;
			}else{
				c[i][aaaa+1]=0;
			}
			aaaa--;
			aaa/=2;
		}
		}
	}
	if(m==1)cout<<d;
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=dd;j++){
				cout<<c[i][j]<<" ";
			}cout<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
