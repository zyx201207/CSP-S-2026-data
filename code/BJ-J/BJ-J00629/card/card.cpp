#include<bits/stdc++.h>
using namespace std;
int a[100005];	
int n,m;
int q[1000005];
int vis[1000005],sum=0;
int vos[10000005];
int size(){
	int res=0;
	for(int i=1;i<=100005;i++){
		if(q[i]==0){
			res=i-1;
			break;
		}
	}
	return res;
}
int push1(int x){
	int l=size();
	q[l+1]=x;
	return 0;
}
bool check1(){
	int l=size();
	for(int i=l-1;i>=1;i--){
		if(q[i]==q[l]) {sum=i; return true;}
	}
	return false;
}
bool check2(int x){
	int l=size();
	for(int i=1;i<=l;i++){
		if(q[i]==x) return true;
	}
	return false;
}
int b[100005];
int push2(int x){
	int j=1;
	for(int i=1;i<=sum-1;i++){
		b[j]=q[i];
		j++;
	}
	memset(q,0,sizeof(q));
	int s=sum-1;
	for(int i=1;i<=s;i++){
		q[i]=b[i];
	}
	q[s+1]=x;
	return 0;
}
bool check3(){
	for(int i=1;i<=n;i++){
		if(a[i]<a[i-1]) return false;
	}
	return true;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(!check3()){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				push1(a[j]);
				if(check1()){
					push2(a[j]);
				}
			}
			for(int j=1;j<=m;j++){
				if(check2(j)){
					vis[j]++;
				}
			}
			memset(q,0,sizeof(q));
		}
		for(int i=1;i<=m;i++){
			cout<<vis[i]<<" ";
		}
	}else{
		for(int i=n;i>=1;i--){
			b[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			if(b[i]==0) cout<<0<<" ";
			else cout<<n-b[i]+1<<" ";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
