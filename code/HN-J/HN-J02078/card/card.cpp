#include<bits/stdc++.h>
using namespace std;
const int N=5.5e5;
int n,a[N],m,b[N];
void f(int k[]){
	int l[N],q=0;
	for(int t=m;t<=n;t++){
		int u;
		for(int i=1;i<=q;i++)
			if(l[i]==a[i])u=i;
		if(u!=-1){
			for(int j=u;j<t;j++)l[j]=0,q--;
		}else l[q]=a[t];
	}for(int i=1;i<=q;i++){
		b[l[q]]++;
	}
}
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
		f(a);
	}for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
