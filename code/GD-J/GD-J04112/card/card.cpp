#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],cnt[N],lis[N],ans;
struct node{
	int pos;
}fg[N];
int main(){
	//ÁîÁîÁîÉêÉêÉêÉêÉêÌá½»Ç°½â³ýÎÄ¼þÊäÈëÊä³ö×¢ÊÍ 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	for(int x = 1; x <= n; x++){
		memset(lis,0,sizeof(lis));
//		memset(fg,0,sizeof(fg));
		for(int j = x; j <= n; j++){
			if(fg[a[j]].pos){
				for(int i = fg[a[j]].pos; i <= j; i++){
					fg[lis[i]].pos=0;
				}
			}
			lis[j-x+1]=a[j];
			fg[a[j]].pos=j-x+1;
		}
		for(int i = 1; i <= m; i++){
			if(fg[i].pos){
				cnt[i]++;
//				cout<<i;
				fg[i].pos=0;
			}
		}
	}
	for(int i = 1; i <= m; i++){
		cout<<cnt[i]<<" ";
	}
} 
