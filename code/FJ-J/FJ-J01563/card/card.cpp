#include<bits/stdc++.h>
using namespace std;
int n,m,t=1;
int b[200005],a[200005],an1,an2;
bool f1,f2;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	if(m==1) {
		cout<<n;
		return 0;
	}
	if(m==2){
		while(t<=n){
			for(int i=1;i<t;i++){
				a[i]=1;
			}
			for(int i=t;i<=n;i++){
				if(b[i]==b[i+1] && a[i]!=2){
					a[i]=2;
				}
				if(b[i]==b[i+2] && a[i]!=2){
					a[i]=2;
					a[i+1]=2;
				}
			}
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					if(b[i]==1) f1=1;
					if(b[i]==2) f2=1;
				}
			}
			if(f1)an1++;
			if(f2)an2++;
			t++;
			f1=0;
			f2=0;
			for(int i=1;i<=n;i++){
				a[i]=0;
			}
		}
}
	cout<<an1<<' '<<an2;
	return 0;
}
