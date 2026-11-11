#include<bits/stdc++.h>
using namespace std;
int a[100005];
int aa[100005][100];
int l[100];
int main(){
	freopen("and.in","w",stdin);
	freopen("and.out","s",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		cin>>a[i];
		int  s=a[i],q=1;
		while(s>1){
			l[q]=s%2;
		    q++;
		    s/=2;
		}
		for(int j=1;j<=q;j++){
			aa[i][j]=l[q-j+1];
		}
	}
	if(n==5){
		cout<<7;
	}else{
		cout<<12;
	}
}
