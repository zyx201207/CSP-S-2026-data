#include<bits/stdc++.h>
using namespace std;
int a[10000]={ },ca[10000]={ },mina=1e7+9,jsp=0,js=1,l,r;
int n,m;
dfs(int m1){
	if(m1-js*ca[1]<0){
		return 0;
	}
	if(m1-js*ca[1]>0){
		js++;
		return dfs(m1-js*ca[1]);
	}
	if(m1-js*ca[1]==0){
		js++;
		return 0;
	}
}
/*
dfs2(int m2){
	if(m2-js*ca[jsp]<0){
		cout<<m2<<endl;
		return 0;
	}
	if(m2-js*ca[jsp]>0){
		if(ca[l-1]<=ca[r+1]){
			l=jsp;
			jsp--;
		}else{
			r=jsp;
			jsp++;
		}
		js++;
		cout<<m2<<endl;
		return dfs2(m2-js*ca[jsp-1]);
	}
	if(m2-js*ca[jsp]==0){
		js++;
		cout<<m2<<endl;
		return 0;
	}
}
*/
int main(){	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w", stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		ca[i]=a[i+1]-a[i];
		if(ca[i]<mina){
			jsp=i;
			mina=ca[i];
		}
	}
	if(n>5000){
		dfs(m);
		cout<<js;
		return 0;
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=1; j<=n;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=1;i<n;i++){
		ca[i]=a[i+1]-a[i];
		if(ca[i]<mina){
			jsp=i;
			mina=ca[i];
		}
	}
	l=jsp;
	r=jsp;
	dfs2(m);
	*/
	/*
	if((m-ca[jsp])>=0){
		js++;
		m-=ca[jsp];
		a[jsp]=a[jsp+1];
		if(jsp!=1){
			ca[jsp-1]=a[jsp]-a[jsp-1];
		} 
		while(m){
			cout<<"a"<<endl;
			if(ca[jsp+1]>ca[jsp-1]&&jsp>1){
				if((m-js*ca[jsp-1])>0){
					js++;
					m-=js*ca[jsp];
					a[jsp]=a[jsp-1];
					jsp--;
					cout<<"b"<<endl;
					if(jsp!=1){
						ca[jsp-1]=a[jsp]-a[jsp-1];
					} 
				}else{
					break;
				}
			}
			if(ca[jsp+1]<ca[jsp-1]){
				if((m-js*ca[jsp+js])>0){
					m-=js*ca[jsp+js];
					a[jsp]=a[jsp+1];
					js++;
					jsp++;
					cout<<"c"<<endl;
					ca[jsp]=a[jsp+1]-a[jsp];
				}else{
					break;
				}
			}
		}
	}
	*/
	cout<<js;
	return 0;
}
