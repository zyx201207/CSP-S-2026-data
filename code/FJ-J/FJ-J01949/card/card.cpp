#include<bits/stdc++.h>
using namespace  std;

int n,m,k;
int a[500005],b[1000005],t[500005],vis[500005];

void init2(){
	for(int i=1;i<=k;i++){
		cout<<b[i]<<" "; 
	}
	cout<<endl;
}

int f(int s){
	for(int i=1;i<=k;i++){
		if(b[i]==s){
			return i;
		}
//		cout<<"s"<<s<<" "<<b[i]<<endl;
	}
//	init2();
	return -1;
}

void qing(){
	for(int i=1;i<=m;i++){
		vis[i]=0;
	}
}

void qing2(){
	for(int i=1;i<=k;i++){
		b[i]=0;
	}
}

void init(){
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" "; 
	}
	cout<<endl;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		qing2();
		for(int j=i;j<=n;j++){
			int h=f(a[j]);
//			cout<<h<<" "<<a[j]<<endl;
			if(h==-1){
				k++;
				b[k]=a[j];
			}else{
				k=h-1;
				k++;
				b[k]=a[j];
			}
//			init2();
		}
		qing();
		for(int i=1;i<=k;i++){
			if(!(vis[ b[i] ]) ){
				vis[b[i]]=1;
				t[b[i]]++;
			}
		}
//		init();
	}
	init();
	return 0;
}
