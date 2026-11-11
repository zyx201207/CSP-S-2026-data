#include<bits/stdc++.h>
using namespace std;
int n,m,t[30004],xt[30004];
int a[30004],b[30004];
int main(){
	memset(a,30004,0);
	memset(t,30004,0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int s;
		cin>>s;
		a[i]=s;
	}
	for(int i=0;i<n;i++){
		memset(xt,30004,0);
		for(int i1=i;i<n;i++){
			b[i-i1]=a[i];
			xt[a[i1]]+=1;
			if(xt[a[i1]]>1){
				int w=n-i-1;
				while(a[w+i]!=xt[a[i1]]) w--;b[w]=0;
			}
			
		}
		for(int i1=i;i1<n;i++){
			t[b[i1]]+=1;
		}
	}
	for(int i=1;t[i]!=0;i++){
		cout<<t[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
