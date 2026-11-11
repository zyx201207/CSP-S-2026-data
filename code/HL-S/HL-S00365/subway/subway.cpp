#include<bits/stdc++.h>
using namespace std;
long long m,n,c[10000005],f=0,A=0,B=0;


long long pd(int num){
	int a=m,b=0,d=0;
	for(int j=num;j>0;j--){
		b=c[num]-c[j];
		a-=b;
		if(a>=0){

			d++;
		}
		else{
			return d;
		}
	}
	return d;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>c[i];
	}
	sort(c+1,c+n+1);
    for(int i=1;i<=n;i++){
    	f=max(f,pd(i));
	}
	cout<<f;
    return 0;

}
