#include<bits/stdc++.h>
using namespace std;
bool B[200005][31]={0};
long long a[200005]={0};
long long P;
bool cmp(int x,int y){
	return x>=y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		P=1;
		int num=1;
		while(1){
			if(P>a[i])break;
			if(P&a[i])B[i][num]=1;
			P*=2;num++; 
		}
	}for(int j=29;j>=1;j--){
		int AND=0,CNT=m;
		for(int i=1;i<=n;i++){
			if(B[i][j]){
				if(AND==0)AND=a[i];
				else AND&=a[i];
				CNT--;
			}if(CNT==0){
				cout<<AND;
				return 0;
			}
		}
	}cout<<0;
	return 0;
} 
