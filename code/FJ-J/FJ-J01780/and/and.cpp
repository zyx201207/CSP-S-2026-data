#include<bits/stdc++.h>
using namespace std;
int num[10000001];	
int num2[10000001];
int n,m;
int mx=0;
bool book[1000001];//用来记录这个数是否参与过计算 
void fn(int past,int x){//用来找book中还未使用过的数 
	if(x==m){
		int cnt = 0;
		bool flag = 0;
		for(int i=1;i<=n;i++){
			if(book[i]==1){
				if(flag==1){
					cnt=cnt&num[i];	
					//cout<<cnt<<"***";
				}
				else {
					flag=1;
					cnt=num[i];
					//cout<<cnt<<"*1*";
				}
			}
		}
		mx=max(mx,cnt);
		//cout<<mx<<"***";
		return ;
	}
	for(int i=1;i<=n-past;i++){
		book[past+i]=1;
		fn(past+i,x+1);
		book[past+i]=0;
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		num2[i]=num[i];
	}
	if(m==1){
		int maxn=num[1];
		for(int i=1;i<=n;i++){
			maxn=max(maxn,num[i]);
		}
		cout<<maxn;
		return 0;
	}
	if(m==2){
		int maxn=num[1]&num[2];
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,num[i]&num[j]); 
				//cout<<maxn<<"***";
			}
		}
		cout<<endl<<maxn;
		return 0;
	} 
	int past=0;
	for(int i=1;i<=m;i++){
		fn(past+1,1);
	}
	cout<<mx;
	return 0;	
}
