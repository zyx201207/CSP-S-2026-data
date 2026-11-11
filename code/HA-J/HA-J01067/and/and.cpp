#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int a[10000005];
struct g{
	string p;
	string k;
};
g c[10000005];
string okk(int a){
	int o=0;
	string b;
    while(a>0){
    	o=o*10+a%2;
    	a=a/2;
    }
    for(int i=1;i<=7;i++){
    	b[i]=o%10;
    	o=o/10;
    }
    return b;
}
int kko(string a){
	int o;
	int ju=2;
	for(int i=1;i<=a.size();i++){
	o=o+a[i]*ju;
	ju=2*ju;}
	return o;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n==1||m==1) cout<<"1";
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i].p=okk(a[i]);
	}
	for(int i=1;i<=m*m/2+1;i++){
		for(int j=i;j<8;j++){
			if((c[i].p[j]==1)&&(c[i+1].p[j]==1)){
				c[i].k[j]=1;
			}
			else c[i].k[j]=0;
		}
	}
	for(int i=1;i<m*m/2+1;i++){
		cout<<max(kko(c[i].k),kko(c[i+1].k));
	}
	return 0;
}
