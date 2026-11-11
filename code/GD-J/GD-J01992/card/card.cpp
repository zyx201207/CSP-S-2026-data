#include<bits/stdc++.h>
//暴力骗分程序68分 
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],st[M],top=0,lst[M],ans[M];
int k;  
struct node{
	int num,len;
}b[5005];
bool pdA(){
	for(int i=1;i<=n;i++){
		if(a[i]<a[i-1]) return 0;
	}
	return 1;
}
bool pdB(){
	int c=0;
	for(int i=1;i<n;i++){
		c+=a[i]!=a[i+1];
	}
	return c<=5000;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(pdA()){
		int c=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]) ans[a[i]]=i;
		}
	}else if(n<=5000){
		for(int i=1;i<=n;i++){
			top=0;
			for(int j=1;j<=m;j++){
				st[j]=lst[j]=0;
			} 
			for(int j=i;j<=n;j++){
				int pos=lst[a[j]];
				if(pos && pos<=top && st[pos]==a[j]){
					st[top=pos]=a[j];
				}else{
					st[++top]=a[j];
					lst[a[j]]=top;
				}
			}
			for(int j=1;j<=top;j++){
				ans[st[j]]++;
			}
		} 
	}else if(pdB()){
		int c=0;
		for(int i=1;i<=n;i++){
			c++;
			if(a[i]!=a[i+1]){
				b[++k]={a[i],c};
				c=0;
			}
		}
		for(int i=1;i<=k;i++){
			top=0;
			for(int j=1;j<=m;j++){
				st[j]=lst[j]=0;
			}
			for(int j=i;j<=k;j++){
				int pos=lst[b[j].num];
				if(pos && pos<=top && st[pos]==b[j].num){
					st[top=pos]=b[j].num;
				}else{
					st[++top]=b[j].num;
					lst[b[j].num]=top;
				}
			}
			for(int j=1;j<=top;j++){
				ans[st[j]]+=b[i].len;
			}
		}
	}else if(m==2){
		int c=0;
		for(int i=1;i<=n;i++){
			c++;
			if(a[i]!=a[i+1]){
				b[++k]={a[i],c};
				c=0;
			}
		}
		for(int i=1;i<=k;i++){
			if(b[i].num!=b[k].num){
				ans[1]+=b[i].len;
				ans[2]+=b[i].len;
			}else ans[b[i].num]+=b[i].len;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}

