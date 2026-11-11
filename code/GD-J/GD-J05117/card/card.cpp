#include<bits/stdc++.h>
using namespace std;
#define int_ long long
//#define frp(i,a,b) for(int_ (i)=(int_)(a);i<=(int_)(b);i++)
const int N=5e5+7,M=3e5+7;
int a[N],bef[M];
int n,m;
int st[N],len;
int ans[M];
void s1(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			bef[j]=0;
		}
		for(int j=1;j<=len;j++){
			st[j]=0;
		}
		len=0;
		for(int j=i;j<=n;j++){
			len++;
			
			if(bef[a[j]] and bef[a[j]]<len){
				for(int k=bef[a[j]]+1;k<=len;k++){
					bef[st[k]]=0;
//					cout<<st[k]<<" ";
					st[k]=0;
				}
				len=bef[a[j]];
			}
					
			st[len]=a[j];
			bef[a[j]]=len;
			
		}
//		cout<<"\n";
		for(int j=1;j<=len;j++){
			ans[st[j]]++;
//			cout<<st[j]<<" ";
		}
//		cout<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return ;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	s1();
	
	return 0;
}
/*
13 6
2 2 3 4 2 3 2 6 2 6 5 2 1
*/
